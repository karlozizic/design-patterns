namespace ConsoleApp1.NumberSource;

public interface ISource<T>
{
    public T ReadInput();
    public int Finished(); 
}