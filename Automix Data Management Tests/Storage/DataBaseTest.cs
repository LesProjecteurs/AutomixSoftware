﻿// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System.Data.SQLite;
using System.IO;
using Automix_Data_Management.Model;
using Automix_Data_Management.Storage;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Automix_Data_Management_Tests.Storage
{

    [TestClass]
    public class DataBaseTest
    {
        private static Track _testTrack;
        private static readonly string[] DataBasePaths = { "db_test_1.db", "db_test_2.db", "db_test_imported.db" };
        private static readonly string[] DataBaseUserPaths = { "../../db_user_test_to_import_1.db", "../../db_user_test_to_import_2.db", "db_user_test_exported.db" };

        [ClassInitialize]
        public static void InitializeTests(TestContext testContext)
        {
            
            foreach (var path in DataBasePaths)
            {
                if (File.Exists(path))
                {
                    File.Delete(path);
                }
            }

            _testTrack = new Track(TestConstant.TestFilePath, TestConstant.TestCheckSum)
            {
                Bpm = 128,
                Key = "6d",
                Beats = new[] { 1, 2, 3 },
                FadeIns = new[] { 2, 3, 5 },
                FadeOuts = new[] { 3, 4, 6 },
                Danceability = 3,
                Duration = 1000,
                Samplerate = 44100
            };
        }

        [TestMethod]
        public void TestAddTrackIntoDataBase()
        {
            var dataBase = new DataBase(DataBasePaths[0]);
            dataBase.Clear();

            Assert.IsFalse(dataBase.IsInDataBase(_testTrack));
            dataBase.AddTrack(_testTrack);
            Assert.IsTrue(dataBase.IsInDataBase(_testTrack));
        }

        [TestMethod]
        public void TestExtractData()
        {
            var dataBase = new DataBase(DataBasePaths[1]);
            dataBase.Clear();

            dataBase.AddTrack(_testTrack);
            var extractedTrack = new Track(TestConstant.TestFilePath, TestConstant.TestCheckSum);
            dataBase.ExtractData(extractedTrack);

            Assert.AreEqual(_testTrack.Duration, extractedTrack.Duration);
            Assert.AreEqual(_testTrack.Bpm, extractedTrack.Bpm);
            Assert.AreEqual(_testTrack.Key, extractedTrack.Key);
            Assert.AreEqual(_testTrack.Samplerate, extractedTrack.Samplerate);
            Assert.AreEqual(_testTrack.Danceability, extractedTrack.Danceability);

            for (var i = 0; i < 3; i++)
            {
                Assert.AreEqual(_testTrack.Beats[i], extractedTrack.Beats[i]);
                Assert.AreEqual(_testTrack.FadeIns[i], extractedTrack.FadeIns[i]);
                Assert.AreEqual(_testTrack.FadeOuts[i], extractedTrack.FadeOuts[i]);

            }
        }
        
        [TestMethod]
        public void TestImportDataBase()
        {
            var db = new DataBase(DataBasePaths[2]);
            db.ImportDataBase(DataBaseUserPaths[0]);

            SQLiteConnection dbUserToImportConnection = new SQLiteConnection("Data Source=" + DataBaseUserPaths[0] + ";Version=3;");
            Assert.IsTrue(db.ChecksumsAreInDataBase(dbUserToImportConnection));
        }


        [TestMethod]
        public void TestExportDataBase()
        {
            var db = new DataBase(DataBaseUserPaths[1]);
            db.ExportDataBase(DataBaseUserPaths[2]);

            SQLiteConnection dbUserConnection = new SQLiteConnection("Data Source=" + DataBaseUserPaths[2] + ";Version=3;");
            Assert.IsTrue(db.ChecksumsAreInDataBase(dbUserConnection));
        }
    }
}
