using ConsoleApp1.NumberSource;
using ConsoleApp1.Observer;
using Timer = System.Threading.Timer;

namespace ConsoleApp1.Observeable;

public class NumberSequenceSubject : ObserveableWithTimer
{
    private List<int> _numbers;
    private ISource<int> _source;
    private List<IObserver> _observers;
    private bool _finished = false;
    
    public NumberSequenceSubject(ISource<int> source)
    {
        _numbers = new List<int>();
        _source = source;
        _observers = new List<IObserver>();
    }
    
    public void AddObserver(IObserver observer)
    {
        _observers.Add(observer);
    }

    public void AddMultipleObservers(List<IObserver> observers)
    {
        _observers.AddRange(observers);
    }

    public void Start()
    {
        _timer = new Timer(TimerEventCallback, null, 0, _interval);
        while (true)
        {
            if (_finished) break;
        }
    }
    
    protected override void TimerEventCallback(object? state)
    {
        var number = _source.ReadInput();
        if (number != _source.Finished())
        {
            _numbers.Add(number);
            NotifyObservers();
        }
        else
        {
            _timer.Dispose();
            _finished = true;
        }
    }
    
    protected override void NotifyObservers()
    {
        foreach (var observer in _observers)
        {
            observer.Update(_numbers);
        }
    }
}