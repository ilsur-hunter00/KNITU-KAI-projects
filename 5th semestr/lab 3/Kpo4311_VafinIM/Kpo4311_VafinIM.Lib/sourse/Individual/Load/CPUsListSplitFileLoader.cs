using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Kpo4311.VafinIM.Lib
{
    public class CPUsListSplitFileLoader : ICPUsListLoader
    {
        public CPUsListSplitFileLoader(string dataFileName)
        {
            _dataFileName = dataFileName;
        }

        private readonly string _dataFileName;
        private List<CPUs> _CPUsList = null;
        private ICPUsListLoader.LoadStatus _status = ICPUsListLoader.LoadStatus.None;

        public List<CPUs> CPUsList
        {
            get { return _CPUsList; }
        }
        public ICPUsListLoader.LoadStatus status
        {
            get { return _status; }
        }

        public void Execute()
        {

            //Инициализировать статус выполнения чтения данных 
            _status = ICPUsListLoader.LoadStatus.None;

            //Если имя файла не указано то вызвать искючение
            if (_dataFileName == "")
            {
                _status = ICPUsListLoader.LoadStatus.FileNameIsEmpty;
                throw new Exception("Путь к файлу не указан");
            }
            //Если файл не существует то вызвать искючение
            if (!File.Exists(_dataFileName))
            {
                _status = ICPUsListLoader.LoadStatus.FileNotExists;
                throw new Exception("Файл не найден");
            }


            //..прочитать файл построчно
            StreamReader sr = null;
            using (sr = new StreamReader(_dataFileName))
            {
                while (!sr.EndOfStream)
                {
                    string str = sr.ReadLine();

                    try
                    {
                        string[] arr = str.Split('|');
                        CPUs cpu = new CPUs
                        {
                            CPU = arr[0],
                            frequency = int.Parse(arr[1]),
                            RAM = int.Parse(arr[2]),
                            Type = arr[3]

                        };
                        if (_CPUsList == null)
                            _CPUsList = new List<CPUs>();
                        _CPUsList.Add(cpu);
                    }
                    catch (Exception ex)
                    {
                        LogUtility.ErrorLog(ex);
                        _status = ICPUsListLoader.LoadStatus.GeneralError;
                    }
                }
            }
            _status = ICPUsListLoader.LoadStatus.Success;
        }
    }
}
