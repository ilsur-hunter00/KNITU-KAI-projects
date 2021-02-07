using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.VafinIM.Lib
{
    class CPUsListSplitFileSaver : ICPUsListSaver
    {
        private readonly string _datafilename;
        private List<CPUs> _CPUsList;
        public CPUsListSplitFileSaver(string datafilename)
        {
            _datafilename = datafilename;
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
            _status = ICPUsListSaver.LoadStatus.None;

            if (_datafilename == "")
            {
                _status = ICPUsListSaver.LoadStatus.FileNameIsEmpty;
                throw new Exception("Путь к файлу пуст");
            }

            if (_CPUsList == null)
            {
                _status = ICPUsListSaver.LoadStatus.NoData;
                throw new Exception("Данных нет");
            }

            using (StreamWriter sw = new StreamWriter(_datafilename, false))
            {
                if (_CPUsList.Count != 0)
                    for (int i = 0; i < _CPUsList.Count; i++)
                    {
                        try
                        {
                            CPUs cpu = _CPUsList.ElementAt(i);
                            sw.WriteLine(cpu.CPU + '|' + cpu.frequency + '|' + cpu.RAM + '|' + cpu.Type);
                        }
                        catch (Exception ex)
                        {
                            LogUtility.ErrorLog(ex);
                            _status = ICPUsListSaver.LoadStatus.GeneralError;
                        }
                    }
            }
            _status = ICPUsListSaver.LoadStatus.Success;
        }
    }
}
