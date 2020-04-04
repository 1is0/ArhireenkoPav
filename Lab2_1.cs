using System;
using System.Text;
using System.Globalization;

namespace Example
{
    class Lab2_1
    {

        static void Main()
        {
            DateTime dt = DateTime.Now; 
            string h = dt.ToString("G", DateTimeFormatInfo.InvariantInfo);
            string h1 = dt.ToString("d", DateTimeFormatInfo.InvariantInfo);
            GetNum(h);
            GetNum(h1);
            Console.WriteLine(DateTime.Now);
        }

        static void GetNum(string h)
        {
            Console.WriteLine(h);
            for (int i = 0; i <= 9; i++)
            {
                int k = 0;
                for (int j = 0; j < h.Length; j++)
                {
                    if (h[j] - 48 == i) k++;
                }
                Console.WriteLine($"{i}: {k}");
            }
        }
    }
}
