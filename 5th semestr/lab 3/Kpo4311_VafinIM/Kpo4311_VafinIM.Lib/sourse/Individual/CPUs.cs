using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.VafinIM.Lib
{
    public class CPUs
    {
        public CPUs()
        {
            CPU = "";
            frequency = 0;
            RAM = 0;
            Type = "";
        }

        public string CPU { get; set; }
        public int frequency { get; set; }
        public int RAM { get; set; }
        public string Type { get; set; }

    }
}
