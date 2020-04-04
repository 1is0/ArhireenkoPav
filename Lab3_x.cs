using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab3_x
{
    class UserInfo
    {
        UserInfo[] data;
        public UserInfo()
        {
            data = new UserInfo[2];
        }
        public UserInfo this[int index]
        {
            get
            {
                return data[index];
            }
            set
            {
                data[index] = value;
            }
        }
        public string name;
        private int age;
        public int Age
        {
            set
            {
                if (value < 0)
                {
                    Console.WriteLine("Error: Age > 0");
                }
                else
                {
                    age = value;
                }
            }
            get { return age; }
        }
        public string none;
        public string company;
        public static int OrganizationID = 62462;
        public UserInfo(string name, int Age, string company, string none)
        {
            this.name = name;
            this.Age = Age;
            this.company = company;
            this.none = none;
        }

        public void writeInConsoleInfo(string name, int Age)
        {
            Console.WriteLine("Имя: {0}\nВозраст: {1}\n", name, Age);
        }

        public void writeInConsoleInfo(string company, string none, int OrganizationID)
        {
            Console.WriteLine("Компания: {0}\nПродукция: {1}\nID: {2}\n", company, none, OrganizationID);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Создаем объект типа UserInfo
            UserInfo people = new UserInfo();
            people[0] = new UserInfo("Alexandr", 26, "Mojang", "Minecraft");
            people[1] = new UserInfo("Elena", 22, "Mojang", "Minecraft");

            // Выведем информацию в консоль
            for (int i = 0; i < 2; i++, UserInfo.OrganizationID++)
            {
                people[i].writeInConsoleInfo(people[i].name, people[i].Age);
                people[i].writeInConsoleInfo(people[i].company, people[i].none, UserInfo.OrganizationID);
            }

            Console.ReadLine();
        }
    }

}