using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

//Журнализация ошибок работы программы
namespace Kpo4311.VafinIM.Lib
{
    public static class LogUtility
    {
        public static void ErrorLog(string message)
        {
            File.AppendAllText("error.log", DateTime.Now + " " + message + "\n");
        }

        public static void ErrorLog(Exception ex)
        {
            File.AppendAllText("error.log", DateTime.Now + " " + ex.Message + "\n");
        }
    }
}
