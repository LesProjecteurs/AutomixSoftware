﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Automix_UI.Forms
{
    public partial class UserDocForm : Form
    {
        public UserDocForm()
        {
            InitializeComponent();
        }

        private void OnOkButtonClick(object sender, EventArgs e) => Close();
    }
}
