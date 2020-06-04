using System;

namespace LR7
{
    class Program
    {
        static void Main(string[] args)
        {
            RatNum a, b;

            Console.WriteLine("Введите 2 части рационального числа: ");
            var forNum = int.Parse(Console.ReadLine());
            var forDenum = int.Parse(Console.ReadLine());
            a = new RatNum(forNum, forDenum);

            Console.WriteLine("И так же для второго числа: ");
            forNum = int.Parse(Console.ReadLine());
            forDenum = int.Parse(Console.ReadLine());
            b = new RatNum(forNum, forDenum);

            Console.WriteLine("Приведение к целым и действительным числам первого рационального числа:");
            int ires = (int)a;
            Console.WriteLine($"Приведение к целым:{ires}");
            double dres = (double)a;
            Console.WriteLine($"Приведение к действительным:{dres}");

            Console.WriteLine("A + B = {0}\n", (a + b).ToString());
            Console.WriteLine("A - B = {0}\n", (a - b).ToString());
            Console.WriteLine("A * B = {0}\n", (a * b).ToString());
            Console.WriteLine("A / B = {0}\n", (a / b).ToString());
            Console.WriteLine(a.Equals(b));

            Console.WriteLine("Сравнение:");
            if (a > b)
            {
                Console.WriteLine("Первое больше второго.");
            }
            else if (a < b)
            {
                Console.WriteLine("Второе больше первого.");
            }
            else
            {
                Console.WriteLine("Они равны.");
            }

            Console.ReadKey();

        }
    }
}