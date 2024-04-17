using Timer = System.Threading.Timer;

namespace ConsoleApp1.Observeable;

public abstract class ObserveableWithTimer
{
    protected Timer _timer;
    protected const int _interval = 1000;

    protected abstract void TimerEventCallback(object? state);
    protected abstract void NotifyObservers();
}