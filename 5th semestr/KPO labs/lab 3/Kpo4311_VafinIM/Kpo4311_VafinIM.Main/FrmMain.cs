using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Kpo4311.VafinIM.Lib;

namespace Kpo4311.VafinIM.Main
{
    public partial class FrmMain : Form
    {
        public FrmMain()
        {
            InitializeComponent();

            label1.Text = "Журнал: " + AppGlobalSettings.logPath +
                "\nИмя файла данных: " + AppGlobalSettings.dataFileName;
        }

        private List<CPUs> CPUsList = null;
        private BindingSource bsCPUs = new BindingSource();

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void MMenu_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void mmFile_Click(object sender, EventArgs e)
        {

        }

        private void mnExit_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void mnOpen_Click(object sender, EventArgs e)
        {
            try
            {
                //Вызов исключения "Метод не реализован"
                //throw new NotImplementedException();
                //Вызов базового исключения
                //throw new Exception("Неправильные входные параметры");
               
                ICPUsListLoader loader = AppGlobalSettings.CPUsFactory.CreateCPUsListLoader();
                loader.Execute();

                CPUsList = loader.CPUsList;
                bsCPUs.DataSource = CPUsList;

                
                dgvMockCPUsListCommand.DataSource = bsCPUs;
            }
            //обработка исключения "Метод не реализован"
            catch (NotImplementedException ex)
            {
                MessageBox.Show("Ошибка №1: " + ex.Message);
                LogUtility.ErrorLog(ex.Message);
            }
            //обработка остальных исключений
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка №2: " + ex.Message);
            }
        }

        private void SStatus_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void dgvMockCPUsListCommand_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void mnCPU_Click(object sender, EventArgs e)
        {
            /*try
            {
                //Вызов исключения "Метод не реализован"
                //throw new NotImplementedException();
                //Вызов базового исключения
                //throw new Exception("Неправильные входные параметры");
                FrmCPUs frmCPUs = new FrmCPUs();
                CPUs cpus = (bsCPUs.Current as CPUs);
                frmCPUs.SetCPUs(cpus);
                frmCPUs.ShowDialog();
            }
            //обработка исключения "Метод не реализован"
            catch (NotImplementedException ex)
            {
                MessageBox.Show("Ошибка №1: " + ex.Message);
            }
            //обработка остальных исключений
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка №2: " + ex.Message);
                LogUtility.ErrorLog("Ошибка №2: " + ex.Message);
            }*/
        }

        private void mnOpenCPU_Click(object sender, EventArgs e)
        {
            try
            {
                //Вызов исключения "Метод не реализован"
                //throw new NotImplementedException();
                //Вызов базового исключения
                //throw new Exception("Неправильные входные параметры");
                FrmCPUs frmCPUs = new FrmCPUs();
                CPUs cpus = (bsCPUs.Current as CPUs);
                frmCPUs.SetCPUs(cpus);
                frmCPUs.ShowDialog();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка №1: " + ex.Message);
                LogUtility.ErrorLog(ex.Message);
            }
            /*FrmCPUs frmCPUs = new FrmCPUs();
            CPUs cpu = (bsCPUs.Current as CPUs);
            frmCPUs.SetCPUs(cpu);
            frmCPUs.ShowDialog();*/
        }

        private void SaveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (CPUsList == null || CPUsList.Count == 0)
                    throw new Exception("Таблица пуста");

                ICPUsListSaver saver = AppGlobalSettings.CPUsFactory.CreateCPUsListSaver();

                saver.CPUsList = CPUsList;
                saver.Execute();
            }
            //обработка исключения "Метод не реализован"
            catch (NotImplementedException ex)
            {
                MessageBox.Show("Ошибка №1: " + ex.Message);
            }
            //обработка остальных исключений
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка №2: " + ex.Message);
                LogUtility.ErrorLog("Ошибка №2: " + ex.Message);
            }
        }
    }
}