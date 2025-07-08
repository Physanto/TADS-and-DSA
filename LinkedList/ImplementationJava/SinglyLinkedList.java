
public class SinglyLinkedList<E>{     

    public static class Node<E> { 

        // elemento que va almacenar.
        private E element;

        // Nodo que apunta a la siguiente direccion de memoria.
        private Node<E> nextNode;

        // Representacion grafica de una lista enlazada con sus nodos.
        //
        //                 NODE                    NODE                      NODE
        //|----------|------|      |----------|------|      |-----------|------|
        //| element1 | dir1 |----->| element2 | dir2 |----->| element-i | dir-i|----->null
        //|----------|------|      |----------|------|      |-----------|------|
        //        |                                                   |
        //        |                                                   |
        //      head (siempre debe apuntar al primer elemento)       tail (siempre debe apuntar al ultimo elemento)

        public Node(E element, Node<E> nextNode){
            this.element = element;
            this.nextNode = nextNode;
        }

        public E getElement() { return element; }

        public Node<E> getNextNode() { return nextNode; }
        public void setNextNode(Node<E> nextNode) { this.nextNode = nextNode; }
    }

    // cantidad de nodos en la lista enlazada
    private int size;

    //Cabeza de la lista enlazada
    private Node<E> head;

    //cola de la lista enlazada
    private Node<E> tail;

    public SinglyLinkedList(){ 
        head = null;
        tail = null;
        size = 0;
    }

    public int size(){ return size; }

    public boolean isEmpty(){ return size == 0; }

    public void addFirst(E element){
        
        head = new Node<E>(element, head);

        // verifica si esta vacia la lista y si es el caso entonces la cola va contener lo mismo que la cabeza
        // ya que solo hay un elemento en la lista.
        if(isEmpty()){
            tail = head;
        }
        size++;
    }

    public void addLast(E element){

        Node<E> newNode = new Node<E>(element, null);

        if(isEmpty()){
            head = newNode;
        }
        else{
            tail.setNextNode(newNode);;    
        }
        tail = newNode;
        size++;
    }


    public static void main(String[] args){

    }
}
