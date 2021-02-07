using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;

namespace Kpo4311.Utility
{
    public class AppConfigUtility
    {
        public string AppSettings(string Name)
        {
            //Если конфигурационный параметр определен 
            //то
            //..вернуть значение параметра в виде строки 
            //иначе
            //..вернуть пустою строку
            string appsettings = ConfigurationManager.AppSettings[Name];
            if (appsettings != null)
                return appsettings;
            else
                return "";
        }
    }
}
