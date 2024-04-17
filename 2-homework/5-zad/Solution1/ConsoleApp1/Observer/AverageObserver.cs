namespace ConsoleApp1.Observer;

public sealed class AverageObserver : IObserver
{
    public AverageObserver()
    {
        
    }
    
    public void Update(List<int> data)
    {
        int average = data.Sum() / data.Count;
        Console.WriteLine($"AverageObserver Event: {average}");
    }
}