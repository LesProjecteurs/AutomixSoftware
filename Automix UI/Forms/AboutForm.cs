﻿// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.Windows.Forms;

namespace Automix_UI.Forms
{
    public partial class AboutForm : Form
    {
        public AboutForm()
        {
            InitializeComponent();
            var text = richTextBox1.Text;
            richTextBox1.Text = string.Format(text, GetEnhancedProductVersion());
        }

        private static string GetEnhancedProductVersion()
        {
            var productVersion = Application.ProductVersion;
            var lastDotIndex = productVersion.LastIndexOf(".", StringComparison.Ordinal);
            if (lastDotIndex > 0)
            {
                productVersion = productVersion.Substring(0, lastDotIndex);
            }
            return productVersion;
        }

        private void OnOkButtonClick(object sender, EventArgs e) => Close();
    }
}