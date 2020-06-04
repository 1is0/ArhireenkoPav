using System;

namespace Lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Приветствуем вас на нашем сайте оптовых закупок ювелирных изделий для вас и вашего бизнеса!");
            Console.WriteLine("Переход к оформлению заказа...");
            int var=0, types=0 , reg = 0;
            bool check;
            Production order = new Usual();
            for(; types != 1 && types != 2 && types!=3; )
            {
                Console.WriteLine("Введите стилистику продукции, что хотели бы заказать:");
                Console.WriteLine("1-Повседневные");
                Console.WriteLine("2-Вечерние");
                Console.WriteLine("3-Что-бы выделиться");
                check = int.TryParse(Console.ReadLine(),out types);
                
            }
            for(; var!=1 && var !=2 && var !=3;)
            {
                Console.WriteLine("Введите размерность вашего заказа:");
                Console.WriteLine("1-малый магазин(100 гр. * 5 шт.)");
                Console.WriteLine("2-средний магазин(200 гр. * 15 шт.)");
                Console.WriteLine("3-корпорация(300 гр. * 40 шт.");
                check = int.TryParse(Console.ReadLine(), out var);
                reg = var - 1;
            }
            var = 0;
            for (; var!=1 && var !=2 && var !=3;)
            {
                Console.WriteLine("Введите материал для изготавления вашего заказа:");
                Console.WriteLine("1-Серебро");
                Console.WriteLine("2-Платина");
                Console.WriteLine("3-Золото");
                check = int.TryParse(Console.ReadLine(), out var);
            }
            var += (reg * 3);
            switch ((Production.Style)types)
            {
                case Production.Style.Usual:
                    order = new Usual((Production.OrderTypes)var);
                    break;
                case Production.Style.Evening:
                    order = new Evening((Production.OrderTypes)var);
                    break;
                case Production.Style.Bright:
                    order = new Bright((Production.OrderTypes)var);
                    break;
            }
            order.Scost(order.Material, order.Mass);
            order.Scost(order.Material, order.Mass, order.Count);
            order.Output();
        }
    }
}
