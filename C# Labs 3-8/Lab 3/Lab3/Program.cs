using System;

namespace Lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Приветствуем вас на нашем сайте оптовых закупок ювелирных изделий для вас и вашего бизнеса!");
            Console.WriteLine("Переход к оформлению заказа...");
            int material, mass, count;
            Console.WriteLine("Введите код материал изделия(1 - серебро, 2 - платина, 3 - золото)");
            material = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите масса драг металла в изделии(граммы):");
            mass = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите количество:");
            Console.WriteLine("(при заказе от 1 шт. % скидки увеличивается относительно кол-ва заказанного, но не более 30)");
            count = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите стоимость создания изделия(ий) ювелиром(% от стоимости изделия, стандарт 10%):");
            JewerelyStore.making = Convert.ToInt32(Console.ReadLine());
            JewerelyStore order = new JewerelyStore(material, mass, count);
            order.Scost(order.Material, order.Mass);
            order.Scost(order.Material, order.Mass, order.Count);
            order.output();
        }
    }
}
