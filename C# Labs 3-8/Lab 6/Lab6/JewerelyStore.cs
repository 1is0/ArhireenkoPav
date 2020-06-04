using System;
using System.Collections.Generic;
using System.Text;

namespace Lab6
{
    abstract class JewerelyStore
    {
        public string[] types = { "Серьги", "Кольца", "Ожерелья" };
        public static int making = 10;
        private int material;
        public int Material
        {
            set
            {
                if (value < 1 ||  value > 3)
                {
                    Console.WriteLine("Ошибка ввода");
                }
                else
                {
                    material = value;
                }
            }
            get
            {
                return material;
            }
        }
        private double mass;
        public double Mass
        {
            set
            {
                if (value <= 0)
                {
                    Console.WriteLine("Ошибка ввода");
                }
                else
                {
                    mass = value;
                }
            }
            get
            {
                return mass;
            }
        }
        private int count;
        public int Count
        {
            set
            {
                if (value <= 0)
                {
                    Console.WriteLine("Ошибка ввода");
                }
                else
                {
                    count = value;
                }
            }
            get
            {
                return count;
            }
        }
        
        public double singlecost;
        public double ordercost;
        public int sale;
        double[] typescost;
        public double this[int index]
        {
            get
            {
                return typescost[index];
            }
        }
        public JewerelyStore()
        {
            material = 1;
            mass = 300;
            count = 900;
        }
        public JewerelyStore(int new_material, double new_mass, int new_count)
        {
            this.Material = new_material;
            this.Mass = new_mass;
            this.Count = new_count;
        }
        public void Scost(int new_material, double new_mass)
        {
            singlecost = new_material * new_mass * 60;
        }
        public void Scost(int new_material, double new_mass, int new_count)
        {
            sale = new_count;
            if (sale > 30) sale = 30;
            ordercost = new_material * new_mass * 60 * new_count * (100 - sale) / 100;
            typescost = new double[3];
            typescost[0] = (ordercost * 1.5) + (ordercost * 1.5 * making / 100);
            typescost[1] = (ordercost * 3) + (ordercost * 3 * making / 100);
            typescost[2] = (ordercost * 8) + (ordercost * 8 * making / 100);
        }
        public virtual void Output()
        {
            Console.WriteLine($"Цена за обработанное изделие:{singlecost}");
            Console.WriteLine($"Цена за отливку и обработку заказа:{ordercost}");
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine(types[i]);
                Console.WriteLine($"Цена гравировки изделия:{this[i]}");
            }
        }
    }
}
