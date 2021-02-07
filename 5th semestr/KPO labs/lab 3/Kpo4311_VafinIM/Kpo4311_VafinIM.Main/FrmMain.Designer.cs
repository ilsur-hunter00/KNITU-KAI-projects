namespace Kpo4311.VafinIM.Main
{
    partial class FrmMain
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.MMenu = new System.Windows.Forms.MenuStrip();
            this.mmFile = new System.Windows.Forms.ToolStripMenuItem();
            this.mnExit = new System.Windows.Forms.ToolStripMenuItem();
            this.mnOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.mnCPU = new System.Windows.Forms.ToolStripMenuItem();
            this.mnOpenCPU = new System.Windows.Forms.ToolStripMenuItem();
            this.SStatus = new System.Windows.Forms.StatusStrip();
            this.dgvMockCPUsListCommand = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.SaveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.MMenu.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvMockCPUsListCommand)).BeginInit();
            this.SuspendLayout();
            // 
            // MMenu
            // 
            this.MMenu.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.MMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mmFile,
            this.mnCPU});
            this.MMenu.Location = new System.Drawing.Point(0, 0);
            this.MMenu.Name = "MMenu";
            this.MMenu.Size = new System.Drawing.Size(800, 30);
            this.MMenu.TabIndex = 0;
            this.MMenu.Text = "menuStrip1";
            this.MMenu.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.MMenu_ItemClicked);
            // 
            // mmFile
            // 
            this.mmFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnOpen,
            this.SaveToolStripMenuItem,
            this.mnExit});
            this.mmFile.Name = "mmFile";
            this.mmFile.Size = new System.Drawing.Size(70, 26);
            this.mmFile.Text = "1&.Файл";
            this.mmFile.Click += new System.EventHandler(this.mmFile_Click);
            // 
            // mnExit
            // 
            this.mnExit.Name = "mnExit";
            this.mnExit.Size = new System.Drawing.Size(224, 26);
            this.mnExit.Text = "Выход";
            this.mnExit.Click += new System.EventHandler(this.mnExit_Click);
            // 
            // mnOpen
            // 
            this.mnOpen.Name = "mnOpen";
            this.mnOpen.Size = new System.Drawing.Size(224, 26);
            this.mnOpen.Text = "Открыть";
            this.mnOpen.Click += new System.EventHandler(this.mnOpen_Click);
            // 
            // mnCPU
            // 
            this.mnCPU.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnOpenCPU});
            this.mnCPU.Name = "mnCPU";
            this.mnCPU.Size = new System.Drawing.Size(123, 26);
            this.mnCPU.Text = "2&.Процессоры";
            this.mnCPU.Click += new System.EventHandler(this.mnCPU_Click);
            // 
            // mnOpenCPU
            // 
            this.mnOpenCPU.Name = "mnOpenCPU";
            this.mnOpenCPU.Size = new System.Drawing.Size(241, 26);
            this.mnOpenCPU.Text = "Открыть процессоры";
            this.mnOpenCPU.Click += new System.EventHandler(this.mnOpenCPU_Click);
            // 
            // SStatus
            // 
            this.SStatus.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.SStatus.Location = new System.Drawing.Point(0, 428);
            this.SStatus.Name = "SStatus";
            this.SStatus.Size = new System.Drawing.Size(800, 22);
            this.SStatus.TabIndex = 1;
            this.SStatus.Text = "statusStrip1";
            this.SStatus.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.SStatus_ItemClicked);
            // 
            // dgvMockCPUsListCommand
            // 
            this.dgvMockCPUsListCommand.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvMockCPUsListCommand.Location = new System.Drawing.Point(0, 96);
            this.dgvMockCPUsListCommand.Name = "dgvMockCPUsListCommand";
            this.dgvMockCPUsListCommand.RowHeadersWidth = 51;
            this.dgvMockCPUsListCommand.RowTemplate.Height = 24;
            this.dgvMockCPUsListCommand.Size = new System.Drawing.Size(529, 210);
            this.dgvMockCPUsListCommand.TabIndex = 2;
            this.dgvMockCPUsListCommand.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvMockCPUsListCommand_CellContentClick_1);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(-3, 386);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "label1";
            // 
            // SaveToolStripMenuItem
            // 
            this.SaveToolStripMenuItem.Name = "SaveToolStripMenuItem";
            this.SaveToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.SaveToolStripMenuItem.Text = "Сохранить";
            this.SaveToolStripMenuItem.Click += new System.EventHandler(this.SaveToolStripMenuItem_Click);
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dgvMockCPUsListCommand);
            this.Controls.Add(this.SStatus);
            this.Controls.Add(this.MMenu);
            this.MainMenuStrip = this.MMenu;
            this.Name = "FrmMain";
            this.Text = "КПО:4311:Вафин";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.MMenu.ResumeLayout(false);
            this.MMenu.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvMockCPUsListCommand)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip MMenu;
        private System.Windows.Forms.ToolStripMenuItem mmFile;
        private System.Windows.Forms.ToolStripMenuItem mnExit;
        private System.Windows.Forms.ToolStripMenuItem mnOpen;
        private System.Windows.Forms.StatusStrip SStatus;
        private System.Windows.Forms.DataGridView dgvMockCPUsListCommand;
        private System.Windows.Forms.ToolStripMenuItem mnCPU;
        private System.Windows.Forms.ToolStripMenuItem mnOpenCPU;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ToolStripMenuItem SaveToolStripMenuItem;
    }
}

