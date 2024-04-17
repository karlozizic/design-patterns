namespace ConsoleApp1.NumberSource;

public class FileSource : ISource<int>
{
    private string _filePath;
    private int _lineNumber = 0;
    private int _fileLines; 

    public FileSource(string path)
    {
        _filePath = path;
        _fileLines = File.ReadLines(_filePath).Count();
    }
    
    public int ReadInput()
    {
        if (_lineNumber < _fileLines)
        {
            int n = int.TryParse(File.ReadLines(_filePath).Skip(_lineNumber).Take(1).First() ?? "", out var num) ? num : -1;
            _lineNumber++;
            return n;
        }

        return Finished();
    }

    public int Finished()
    {
        return -1; 
    }
}