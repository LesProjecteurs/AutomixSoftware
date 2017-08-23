// <copyright file="UtilsTest.cs">Copyright ©  2017</copyright>
using System;
using AutomixDataManagement;
using Microsoft.Pex.Framework;
using Microsoft.Pex.Framework.Validation;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutomixDataManagement.Tests
{
    /// <summary>This class contains parameterized unit tests for Utils</summary>
    [PexClass(typeof(Utils))]
    [PexAllowedExceptionFromTypeUnderTest(typeof(InvalidOperationException))]
    [PexAllowedExceptionFromTypeUnderTest(typeof(ArgumentException), AcceptExceptionSubtypes = true)]
    [TestClassAttribute]
    public partial class UtilsTest
    {
        /// <summary>Test stub for NameFromPath(String)</summary>
        [PexMethod]
        internal string NameFromPathTest(string path)
        {
            string result = Utils.NameFromPath(path);
            return result;
            // TODO: add assertions to method UtilsTest.NameFromPathTest(String)
        }

        /// <summary>Test stub for GetExtension(String)</summary>
        [PexMethod]
        internal string GetExtensionTest(string fileName)
        {
            string result = Utils.GetExtension(fileName);
            return result;
            // TODO: add assertions to method UtilsTest.GetExtensionTest(String)
        }

        /// <summary>Test stub for ConvertToOpenKey(String, String)</summary>
        [PexMethod]
        internal string ConvertToOpenKeyTest(string key, string scale)
        {
            string result = Utils.ConvertToOpenKey(key, scale);
            return result;
            // TODO: add assertions to method UtilsTest.ConvertToOpenKeyTest(String, String)
        }
    }
}
