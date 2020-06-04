using System;
using System.Runtime.InteropServices;

namespace L4_2
{
    class Program
    {
        [DllImport("Project1.dll")]
        public static extern void write();
        static void Main(string[] args)
        {
            write();
        }
    }
}