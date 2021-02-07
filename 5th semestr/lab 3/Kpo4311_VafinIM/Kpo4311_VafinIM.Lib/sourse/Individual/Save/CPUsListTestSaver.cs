using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kpo4311.VafinIM.Lib
{
    public class CPUsListTestSaver : ICPUsListSaver
    {
        private List<CPUs> _CPUsList;
        public CPUsListTestSaver()
        {
            _CPUsList = null;
        }

        public List<CPUs> CPUsList
        {
            set => _CPUsList = value;
        }

        private ICPUsListSaver.LoadStatus _status = ICPUsListSaver.LoadStatus.None;
        public ICPUsListSaver.LoadStatus status
        {
            get => _status;
        }

        public void Execute()
        {
            try
            {
                if (_CPUsList == null) throw new Exception("Данных нет");
                _status = ICPUsListSaver.LoadStatus.Success;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
                LogUtility.ErrorLog(ex);
                _status = ICPUsListSaver.LoadStatus.NoData;
            }
        }
    }
}
