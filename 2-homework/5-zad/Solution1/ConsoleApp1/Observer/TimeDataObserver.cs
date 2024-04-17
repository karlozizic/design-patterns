namespace ConsoleApp1.Observer;

public sealed class TimeDataObserver : IObserver
{
    private string _filePath;
    private List<int> _state;

    public TimeDataObserver(string filePath,
        List<int> state)
    {
        _filePath = filePath;
        _state = state;
    }

    public void Update(List<int> data)
    {
        if (_state.Count != data.Count)
        {
            using (StreamWriter sw = new StreamWriter(_filePath, true))
            {
                for (int i = _state.Count; i < data.Count; i++)
                {
                    String line = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss ") + $"Broj: {data[i]}";
                    _state.Add(data[i]);
                    sw.WriteLine(line);
                }
            }
        }
    }
}