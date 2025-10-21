package stack;

public class ArrayStack<T> {
    private T[] list;
    private int lastPosition = -1;
    private int capacity;

    @SuppressWarnings("unchecked")
    public ArrayStack(int capacity) throws Exception {
        if (capacity < 1)
            throw new Exception("Invalid capacity. It should be least 1");
        this.capacity = capacity;
        this.list = (T[]) new Object[capacity];
    }

    public void push(T value) throws Exception {
        if (this.lastPosition == this.capacity-1)
            throw new Exception("Stack is full.");
        
        this.lastPosition+=1;
        this.list[this.lastPosition] = value;
    }

    public T pop() throws Exception {
        if (this.lastPosition == -1)
            throw new Exception("Empty stack.");
        T value = this.list[this.lastPosition];
        this.list[this.lastPosition] = null;
        this.lastPosition -= 1;
        return value;
    }

    public T peek() throws Exception {
        if (this.lastPosition == -1)
            throw new Exception("Empty stack.");
        return this.list[this.lastPosition];
    }
}
