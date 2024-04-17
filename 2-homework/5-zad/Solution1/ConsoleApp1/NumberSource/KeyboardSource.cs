namespace ConsoleApp1.NumberSource;

public class KeyboardSource : ISource<int>
{
    public int ReadInput()
    {
        Console.WriteLine("Unesite broj: ");
        int num = int.TryParse(Console.ReadLine(), out var r) ? r : -1;
        return num;
    }

    public int Finished()
    {
        return -1;
    }
}