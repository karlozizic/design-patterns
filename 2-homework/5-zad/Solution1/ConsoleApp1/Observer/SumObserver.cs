namespace ConsoleApp1.Observer;

public sealed class SumObserver : IObserver
{
    public SumObserver()
    {
        
    }
    
    public void Update(List<int> data)
    {
        int sum = data.Sum();
        Console.WriteLine($"SumObserver Event: {sum}");
    }
}