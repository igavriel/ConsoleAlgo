using System;

namespace ConsoleAlgoCs
{
    class Person
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public override string ToString()
        {
            return $"[{Id}] {Name}";
        }
    }

    class PersonWrapper
    {
        public Person P { get; set; }

        public override string ToString()
        {
            return $"{P}";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person A = new Person { Id = 111, Name = "AAAAA" };
            Person B = new Person { Id = 222, Name = "BBBBB" };

            Console.WriteLine($"A==B {A == B}");
            Console.WriteLine($"A={A}, B={B}");
            bad_swap(A, B);
            Console.WriteLine($"A={A}, B={B}");
            ref_swap(ref A, ref B);
            Console.WriteLine($"A={A}, B={B}");

            PersonWrapper PA = new PersonWrapper { P = A };
            PersonWrapper PB = new PersonWrapper { P = B };
            Console.WriteLine($"PA={PA}, PB={PB}");
            noref_swap(PA, PB);
            Console.WriteLine($"PA={PA}, PB={PB}");
        }

        public static void bad_swap(object a, object b)
        {
            object c = a;
            a = b;
            b = c;
        }

        public static void ref_swap(ref Person a, ref Person b)
        {
            Person c = a;
            a = b;
            b = c;
        }

        public static void noref_swap(PersonWrapper a, PersonWrapper b)
        {
            PersonWrapper c = new PersonWrapper { P = new Person()  };
            c.P = a.P;
            a.P = b.P;
            b.P = c.P;
        }
    }
}
