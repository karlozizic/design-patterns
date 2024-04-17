namespace ConsoleApp1.Observer;

public sealed class MedianObserver : IObserver
{
    public MedianObserver()
    {
        
    }
    
    public void Update(List<int> data)
    {
        int median;
        var sortedData = data.OrderBy(x => x).ToList();
        int midInd = sortedData.Count / 2;
        if (sortedData.Count % 2 == 0)
        {
            median = (sortedData[midInd] + sortedData[midInd]) / 2;
        }
        else
        {
            median = sortedData[midInd];
        }
        Console.WriteLine($"MedianObserver Event: {median}");
    }
}