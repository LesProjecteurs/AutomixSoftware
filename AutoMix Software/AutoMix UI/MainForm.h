// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "ViewWithTrackCollection.h"
#include "Presenter.h"

namespace AutoMixUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace AutoMixDataManagement;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form, public ViewWithTrackCollection
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			_presenter = gcnew Presenter(this);

			_cancelMenuItem->Enabled = false;
			_generateButton->Enabled = false;
			_sortButton->Enabled = false;
			_toolStripProgressBar->Visible = false;
			AnOperationRunning = false;

			InsertionLineColor = Color::LightGray;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Presenter^ _presenter;

		property bool IsRowDragInProgress;
		property bool IsDragImportInProgress;
		property bool AnOperationRunning;

		enum class InsertionModeType
		{
			Before,
			After
		};

		property int InsertionIndex;
		property InsertionModeType InsertionMode;
		property Color InsertionLineColor;

	private: System::Windows::Forms::MenuStrip^  _menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  _fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _importMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  _quitMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _aboutMenuItem;
	private: System::Windows::Forms::StatusStrip^  _statusStrip;
	private: System::Windows::Forms::ListView^  _musicListView;
	private: System::Windows::Forms::ColumnHeader^  collectionDuration;
	private: System::Windows::Forms::ColumnHeader^  collectionBPM;
	private: System::Windows::Forms::ColumnHeader^  collectionName;
	private: System::Windows::Forms::Button^  _importButton;
	private: System::Windows::Forms::Button^  _generateButton;
	private: System::Windows::Forms::PictureBox^  _logo;
	private: System::Windows::Forms::ColumnHeader^  collectionKey;
	private: System::Windows::Forms::Button^  _sortButton;
	private: System::Windows::Forms::ToolStripMenuItem^  _cancelMenuItem;
	private: System::ComponentModel::BackgroundWorker^  _importBackgroundWorker;
	private: System::ComponentModel::BackgroundWorker^  _sortBackgroundWorker;
	private: System::Windows::Forms::ToolStripProgressBar^  _toolStripProgressBar;
	private: System::Windows::Forms::ToolStripStatusLabel^  _toolStripCurrentDir;
	private: System::Windows::Forms::ToolStripMenuItem^  _optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _dataBaseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  _clearDBMenuItem;
	private: System::ComponentModel::BackgroundWorker^  _exportBackgroundWorker;
	private: System::Windows::Forms::ToolTip^  _toolTip;
	private: System::Windows::Forms::ContextMenuStrip^  _trackContextMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  _deleteTrackToolStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  _selectAllToolStrip;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->_menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->_fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_importMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_cancelMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->_quitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_dataBaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_clearDBMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_aboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->_toolStripProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->_toolStripCurrentDir = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->_musicListView = (gcnew System::Windows::Forms::ListView());
			this->collectionName = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionDuration = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionBPM = (gcnew System::Windows::Forms::ColumnHeader());
			this->collectionKey = (gcnew System::Windows::Forms::ColumnHeader());
			this->_trackContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->_deleteTrackToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_selectAllToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_importButton = (gcnew System::Windows::Forms::Button());
			this->_generateButton = (gcnew System::Windows::Forms::Button());
			this->_logo = (gcnew System::Windows::Forms::PictureBox());
			this->_sortButton = (gcnew System::Windows::Forms::Button());
			this->_importBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->_sortBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->_exportBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->_toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->_menuStrip->SuspendLayout();
			this->_statusStrip->SuspendLayout();
			this->_trackContextMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_logo))->BeginInit();
			this->SuspendLayout();
			// 
			// _menuStrip
			// 
			this->_menuStrip->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_menuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->_menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->_fileToolStripMenuItem,
					this->_optionsToolStripMenuItem, this->_helpToolStripMenuItem
			});
			this->_menuStrip->Location = System::Drawing::Point(0, 0);
			this->_menuStrip->Name = L"_menuStrip";
			this->_menuStrip->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->_menuStrip->Size = System::Drawing::Size(1264, 24);
			this->_menuStrip->TabIndex = 2;
			this->_menuStrip->Text = L"menuStrip1";
			// 
			// _fileToolStripMenuItem
			// 
			this->_fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->_importMenuItem,
					this->_cancelMenuItem, this->toolStripSeparator, this->_quitMenuItem
			});
			this->_fileToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->_fileToolStripMenuItem->Name = L"_fileToolStripMenuItem";
			this->_fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->_fileToolStripMenuItem->Text = L"&File";
			// 
			// _importMenuItem
			// 
			this->_importMenuItem->Checked = true;
			this->_importMenuItem->CheckState = System::Windows::Forms::CheckState::Indeterminate;
			this->_importMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_importMenuItem.Image")));
			this->_importMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->_importMenuItem->Name = L"_importMenuItem";
			this->_importMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->_importMenuItem->Size = System::Drawing::Size(155, 22);
			this->_importMenuItem->Text = L"&Open...";
			this->_importMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_openToolStripMenuItem_Click);
			// 
			// _cancelMenuItem
			// 
			this->_cancelMenuItem->Name = L"_cancelMenuItem";
			this->_cancelMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->_cancelMenuItem->Size = System::Drawing::Size(155, 22);
			this->_cancelMenuItem->Text = L"&Cancel";
			this->_cancelMenuItem->ToolTipText = L"Cancel all operations";
			this->_cancelMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_cancelToolStripMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(152, 6);
			// 
			// _quitMenuItem
			// 
			this->_quitMenuItem->Name = L"_quitMenuItem";
			this->_quitMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Q));
			this->_quitMenuItem->Size = System::Drawing::Size(155, 22);
			this->_quitMenuItem->Text = L"&Quit";
			this->_quitMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_quitToolStripMenuItem_Click);
			// 
			// _optionsToolStripMenuItem
			// 
			this->_optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_dataBaseToolStripMenuItem });
			this->_optionsToolStripMenuItem->Name = L"_optionsToolStripMenuItem";
			this->_optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->_optionsToolStripMenuItem->Text = L"&Options";
			this->_optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_clearDBToolStripMenuItem_Click);
			// 
			// _dataBaseToolStripMenuItem
			// 
			this->_dataBaseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_clearDBMenuItem });
			this->_dataBaseToolStripMenuItem->Name = L"_dataBaseToolStripMenuItem";
			this->_dataBaseToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->_dataBaseToolStripMenuItem->Text = L"&Database";
			// 
			// _clearDBMenuItem
			// 
			this->_clearDBMenuItem->Name = L"_clearDBMenuItem";
			this->_clearDBMenuItem->Size = System::Drawing::Size(101, 22);
			this->_clearDBMenuItem->Text = L"&Clear";
			this->_clearDBMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_clearDBToolStripMenuItem_Click);
			// 
			// _helpToolStripMenuItem
			// 
			this->_helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->_aboutMenuItem });
			this->_helpToolStripMenuItem->Name = L"_helpToolStripMenuItem";
			this->_helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->_helpToolStripMenuItem->Text = L"&Help";
			// 
			// _aboutMenuItem
			// 
			this->_aboutMenuItem->Name = L"_aboutMenuItem";
			this->_aboutMenuItem->Size = System::Drawing::Size(116, 22);
			this->_aboutMenuItem->Text = L"&About...";
			this->_aboutMenuItem->Click += gcnew System::EventHandler(this, &MainForm::_aboutToolStripMenuItem_Click);
			// 
			// _statusStrip
			// 
			this->_statusStrip->AccessibleName = L"_statusStrip";
			this->_statusStrip->BackColor = System::Drawing::SystemColors::GrayText;
			this->_statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_toolStripProgressBar,
					this->_toolStripCurrentDir
			});
			this->_statusStrip->Location = System::Drawing::Point(0, 660);
			this->_statusStrip->Name = L"_statusStrip";
			this->_statusStrip->Size = System::Drawing::Size(1264, 22);
			this->_statusStrip->TabIndex = 3;
			this->_statusStrip->Text = L"statusStrip1";
			// 
			// _toolStripProgressBar
			// 
			this->_toolStripProgressBar->Margin = System::Windows::Forms::Padding(3, 3, 1, 3);
			this->_toolStripProgressBar->Maximum = 1000;
			this->_toolStripProgressBar->Name = L"_toolStripProgressBar";
			this->_toolStripProgressBar->Size = System::Drawing::Size(150, 16);
			// 
			// _toolStripCurrentDir
			// 
			this->_toolStripCurrentDir->Margin = System::Windows::Forms::Padding(5, 3, 0, 2);
			this->_toolStripCurrentDir->Name = L"_toolStripCurrentDir";
			this->_toolStripCurrentDir->Size = System::Drawing::Size(0, 17);
			// 
			// _musicListView
			// 
			this->_musicListView->AccessibleName = L"_musicListView";
			this->_musicListView->AllowDrop = true;
			this->_musicListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->_musicListView->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_musicListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->collectionName,
					this->collectionDuration, this->collectionBPM, this->collectionKey
			});
			this->_musicListView->ContextMenuStrip = this->_trackContextMenu;
			this->_musicListView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_musicListView->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->_musicListView->FullRowSelect = true;
			this->_musicListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->_musicListView->Location = System::Drawing::Point(0, 275);
			this->_musicListView->Name = L"_musicListView";
			this->_musicListView->Size = System::Drawing::Size(1264, 381);
			this->_musicListView->TabIndex = 4;
			this->_musicListView->UseCompatibleStateImageBehavior = false;
			this->_musicListView->View = System::Windows::Forms::View::Details;
			this->_musicListView->ItemDrag += gcnew System::Windows::Forms::ItemDragEventHandler(this, &MainForm::_musicListView_ItemDrag);
			this->_musicListView->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::_musicListView_DragDrop);
			this->_musicListView->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::_musicListView_DragEnter);
			this->_musicListView->DragOver += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::_musicListView_DragOver);
			// 
			// collectionName
			// 
			this->collectionName->Text = L"Name";
			this->collectionName->Width = 681;
			// 
			// collectionDuration
			// 
			this->collectionDuration->Text = L"Duration";
			this->collectionDuration->Width = 162;
			// 
			// collectionBPM
			// 
			this->collectionBPM->Text = L"BPM";
			this->collectionBPM->Width = 72;
			// 
			// collectionKey
			// 
			this->collectionKey->Text = L"Key";
			this->collectionKey->Width = 71;
			// 
			// _trackContextMenu
			// 
			this->_trackContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->_deleteTrackToolStrip,
					this->_selectAllToolStrip
			});
			this->_trackContextMenu->Name = L"_listViewcontextMenu";
			this->_trackContextMenu->Size = System::Drawing::Size(165, 48);
			this->_trackContextMenu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::_listViewcontextMenu_Opening);
			// 
			// _deleteTrackToolStrip
			// 
			this->_deleteTrackToolStrip->Enabled = false;
			this->_deleteTrackToolStrip->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_deleteTrackToolStrip.Image")));
			this->_deleteTrackToolStrip->Name = L"_deleteTrackToolStrip";
			this->_deleteTrackToolStrip->ShortcutKeys = System::Windows::Forms::Keys::Delete;
			this->_deleteTrackToolStrip->Size = System::Drawing::Size(164, 22);
			this->_deleteTrackToolStrip->Text = L"&Remove";
			this->_deleteTrackToolStrip->Click += gcnew System::EventHandler(this, &MainForm::toolStripDeleteTrack_Click);
			// 
			// _selectAllToolStrip
			// 
			this->_selectAllToolStrip->Name = L"_selectAllToolStrip";
			this->_selectAllToolStrip->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->_selectAllToolStrip->Size = System::Drawing::Size(164, 22);
			this->_selectAllToolStrip->Text = L"Select All";
			this->_selectAllToolStrip->Click += gcnew System::EventHandler(this, &MainForm::selectAllToolStripMenuItem_Click);
			// 
			// _importButton
			// 
			this->_importButton->AccessibleName = L"_importButton";
			this->_importButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_importButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_importButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_importButton->Location = System::Drawing::Point(70, 114);
			this->_importButton->Name = L"_importButton";
			this->_importButton->Size = System::Drawing::Size(147, 78);
			this->_importButton->TabIndex = 5;
			this->_importButton->Text = L"Import Tracks";
			this->_toolTip->SetToolTip(this->_importButton, L"Click to import new tracks");
			this->_importButton->UseVisualStyleBackColor = false;
			this->_importButton->Click += gcnew System::EventHandler(this, &MainForm::_imputButton_Click);
			// 
			// _generateButton
			// 
			this->_generateButton->AccessibleName = L"_generateButton";
			this->_generateButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_generateButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_generateButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_generateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_generateButton->Location = System::Drawing::Point(1054, 67);
			this->_generateButton->Name = L"_generateButton";
			this->_generateButton->Size = System::Drawing::Size(147, 78);
			this->_generateButton->TabIndex = 6;
			this->_generateButton->Text = L"Generate Mix";
			this->_toolTip->SetToolTip(this->_generateButton, L"Click to export an mp3 file");
			this->_generateButton->UseVisualStyleBackColor = false;
			this->_generateButton->Click += gcnew System::EventHandler(this, &MainForm::_outputButton_Click);
			// 
			// _logo
			// 
			this->_logo->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->_logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"_logo.Image")));
			this->_logo->Location = System::Drawing::Point(311, 38);
			this->_logo->Name = L"_logo";
			this->_logo->Size = System::Drawing::Size(653, 226);
			this->_logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->_logo->TabIndex = 7;
			this->_logo->TabStop = false;
			// 
			// _sortButton
			// 
			this->_sortButton->AccessibleName = L"_sortButton";
			this->_sortButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->_sortButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->_sortButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->_sortButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_sortButton->Location = System::Drawing::Point(1054, 174);
			this->_sortButton->Name = L"_sortButton";
			this->_sortButton->Size = System::Drawing::Size(147, 78);
			this->_sortButton->TabIndex = 8;
			this->_sortButton->Text = L"Sort";
			this->_toolTip->SetToolTip(this->_sortButton, L"Click to sort tracks using AutoMix AI");
			this->_sortButton->UseVisualStyleBackColor = false;
			this->_sortButton->Click += gcnew System::EventHandler(this, &MainForm::_sortButton_click);
			// 
			// _importBackgroundWorker
			// 
			this->_importBackgroundWorker->WorkerReportsProgress = true;
			this->_importBackgroundWorker->WorkerSupportsCancellation = true;
			this->_importBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::_backgroundWorker1_DoWork);
			this->_importBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::_backgroundWorker1_ProgressChanged);
			this->_importBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::_backgroundWorker1_RunWorkerCompleted);
			// 
			// _sortBackgroundWorker
			// 
			this->_sortBackgroundWorker->WorkerReportsProgress = true;
			this->_sortBackgroundWorker->WorkerSupportsCancellation = true;
			this->_sortBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::_backgroundWorker2_DoWork);
			this->_sortBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::_backgroundWorker2_ProgressChanged);
			this->_sortBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::_backgroundWorker2_RunWorkerCompleted);
			// 
			// _exportBackgroundWorker
			// 
			this->_exportBackgroundWorker->WorkerReportsProgress = true;
			this->_exportBackgroundWorker->WorkerSupportsCancellation = true;
			this->_exportBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::_backgroundWorker3_DoWork);
			this->_exportBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::_backgroundWorker3_ProgressChanged);
			this->_exportBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::_backgroundWorker3_RunWorkerCompleted);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1264, 682);
			this->Controls->Add(this->_sortButton);
			this->Controls->Add(this->_logo);
			this->Controls->Add(this->_generateButton);
			this->Controls->Add(this->_importButton);
			this->Controls->Add(this->_musicListView);
			this->Controls->Add(this->_statusStrip);
			this->Controls->Add(this->_menuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->_menuStrip;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(1280, 720);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AutoMix Software";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
			this->_menuStrip->ResumeLayout(false);
			this->_menuStrip->PerformLayout();
			this->_statusStrip->ResumeLayout(false);
			this->_statusStrip->PerformLayout();
			this->_trackContextMenu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_logo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		System::Void update(TrackCollection^) override;

	private:
		System::Void onWorkerStart();
		System::Void onWorkerStop();
		System::Void showCancelDialog();
		System::Void showErrorDialog(System::String^);
		bool showExitDialog();
		System::Void exitApplication();
		System::Void MainForm::DrawInsertionLine();
		System::Void MainForm::DrawInsertionLine(int x1, int y, int width);

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}

	private: System::Void _quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void loadTracks(System::Object^  sender, System::EventArgs^  e);
	private: System::Void exportTrackList(System::Object^  sender, System::EventArgs^  e);
	private: System::Void sortTracksWithGeneticAlgorithm(System::Object^ sender, System::EventArgs^ e);
	private: System::Void _imputButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _outputButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _sortButton_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void _backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void _backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void _cancelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void _backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void _aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _clearDBToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
	private: System::Void _backgroundWorker2_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
	private: System::Void _backgroundWorker3_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	private: System::Void _backgroundWorker3_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
	private: System::Void _backgroundWorker3_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
	private: System::Void toolStripDeleteTrack_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _listViewcontextMenu_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
	private: System::Void selectAllToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void _musicListView_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void _musicListView_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void _musicListView_ItemDrag(System::Object^  sender, System::Windows::Forms::ItemDragEventArgs^  e);
	private: System::Void _musicListView_DragOver(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	};

}
