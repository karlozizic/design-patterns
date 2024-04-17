using ConsoleApp1.NumberSource;
using ConsoleApp1.Observeable;
using ConsoleApp1.Observer;

KeyboardSource source = new KeyboardSource();
/*FileSource source = new FileSource("C:\\Users\\karlo\\OneDrive\\Desktop\\ooup-2lab\\5-zad\\Solution1\\ConsoleApp1\\file.txt");*/
AverageObserver averageObserver = new AverageObserver();
SumObserver sumObserver = new SumObserver();
TimeDataObserver timeDataObserver = new TimeDataObserver("C:\\Users\\karlo\\OneDrive\\Desktop\\ooup-2lab\\5-zad\\Solution1\\ConsoleApp1\\timedata.txt", new List<int>());
MedianObserver medianObserver = new MedianObserver();
NumberSequenceSubject numberSequenceSubject = new NumberSequenceSubject(source);

numberSequenceSubject.AddObserver(averageObserver);
numberSequenceSubject.AddObserver(sumObserver);
numberSequenceSubject.AddObserver(timeDataObserver);
numberSequenceSubject.AddObserver(medianObserver);
numberSequenceSubject.Start();