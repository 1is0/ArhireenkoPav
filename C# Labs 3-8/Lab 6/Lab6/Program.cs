using System;

namespace Lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Приветствуем вас на нашем сайте оптовых закупок ювелирных изделий для вас и вашего бизнеса!");
            Console.WriteLine("Переход к оформлению заказа...");
            int count = 2, i;
            int[] var = new int[count];
            int[] types = new int[count]; 
            int[] reg = new int[count];
            bool check;
            Production[] order = new Production[count];
            for (i = 0; i < count; i++)
            {
                for (; types[i] != 1 && types[i] != 2 && types[i] != 3;)
                {
                    Console.WriteLine("Введите стилистику продукции, что хотели бы заказать:");
                    Console.WriteLine("1-Повседневные");
                    Console.WriteLine("2-Вечерние");
                    Console.WriteLine("3-Что-бы выделиться");
                    check = int.TryParse(Console.ReadLine(), out types[i]);

                }
                for (; var[i] != 1 && var[i] != 2 && var[i] != 3;)
                {
                    Console.WriteLine("Введите размерность вашего заказа:");
                    Console.WriteLine("1-малый магазин(100 гр. * 5 шт.)");
                    Console.WriteLine("2-средний магазин(200 гр. * 15 шт.)");
                    Console.WriteLine("3-корпорация(300 гр. * 40 шт.");
                    check = int.TryParse(Console.ReadLine(), out var[i]);
                    reg[i] = var[i] - 1;
                }
                var[i] = 0;
                for (; var[i] != 1 && var[i] != 2 && var[i] != 3;)
                {
                    Console.WriteLine("Введите материал для изготавления вашего заказа:");
                    Console.WriteLine("1-Серебро");
                    Console.WriteLine("2-Платина");
                    Console.WriteLine("3-Золото");
                    check = int.TryParse(Console.ReadLine(), out var[i]);
                }
                var[i] += (reg[i] * 3);
                switch ((Production.Style)types[i])
                {
                    case Production.Style.Usual:
                        order[i] = new Usual((Production.OrderTypes)var[i]);
                        break;
                    case Production.Style.Evening:
                        order[i] = new Evening((Production.OrderTypes)var[i]);
                        break;
                    case Production.Style.Bright:
                        order[i] = new Bright((Production.OrderTypes)var[i]);
                        break;
                }
                if (i==0) Console.WriteLine("Начат подбор второго заказа для сравнения, пожалуйста выберите еще один");
            }
            for (i = 0; i < count; i++)
            {
                order[i].Up(order[i]);
                order[i].Scost(order[i].Material, order[i].Mass);
                order[i].Scost(order[i].Material, order[i].Mass, order[i].Count);
                order[i].Output();
            }
            if (order[0].Compare(order[1]) > 0)
                Console.WriteLine("Второй заказ дешевле.");
            else if (order[0].Compare(order[1]) < 0)
                Console.WriteLine("Первый заказ дешевле.");
            else Console.WriteLine("Стоимость заказов равна.");
        }
    }
}
