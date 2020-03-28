using System;
using System.Text;
using System.Globalization;

namespace Example
{
    class Program
    {

        static void Main()
        {
            int k;
            DateTime dt = DateTime.Now; 
            string h = dt.ToString("G", DateTimeFormatInfo.InvariantInfo);
            string h1 = dt.ToString("d", DateTimeFormatInfo.InvariantInfo);
            Console.WriteLine(h);
            for (int i = 0; i <= 9; i++)
            {
                k = 0;
                for (int j = 0; j <= 18; j++)
                {
                    if (h[j] - 48 == i) k++; 
                    }
                Console.WriteLine($"{i}: {k}");
            }
            Console.WriteLine(h1);
            for (int i = 0; i <= 9; i++)
            {
                k = 0;
                for (int j = 0; j <= 9; j++)
                {
                    if (h[j] - 48 == i) k++;
                }
                Console.WriteLine($"{i}: {k}");
            }
            Console.WriteLine(DateTime.Now);
        }
    }
}