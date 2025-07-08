public class SinglyLinkedListHead<E> {

    private static class Node<E> { 

        //elemento que va ser almacenado
        private E element;

        // siguiente nodo
        private Node<E> next;

        public Node(E element){
            this.element = element;
            next = null;
        }

        public E getElement() { return element; }

        public Node<E> getNext(){ return next; }
        public void setNext(Node<E> next) { this.next = next; }
    }

    //Cabeza del nodo
    private Node<E> head;

    //cantidad de elementos que hay en la lista
    private int size;

    public SinglyLinkedListHead(){ 
        head = null;
        size = 0;
    }

    public int size() { return size; }

    public boolean isEmpty(){ return size == 0; }

    public void addFirst(E element){
        
        //se crea el nodo nuevo que se va agregar
        Node<E> newNode = new Node<E>(element);
        
        //para yo poder agregar el nuevo nodo a la lista no puedo dejar sin seguimiento al nodo que lo estaba apuntanto el head
        //asi que primero este nuevo nodo va apuntar al nodo anterior(es decir al que estaba apuntado el head antes)
        newNode.setNext(head);

        //ahora ya digo que el head esta apuntando o ya se convierte en el nodo "header"
        head = newNode;

        //aumento el tamano de la lista
        size++;
    }

    public void addLast(E element){

        // si la lista esta vacia, entonces anade el elemento y el head le hace seguimiento.
        // esto con ayuda del metodo addFirst
        if(isEmpty()){ 
            addFirst(element);
            return;
        }
        
        // se crea un nodo auxiliar que es el encargado de almacenar lo que tenga la cabecera
        Node<E> currentNode = head;

        // se hace un recorrido y por cada nodo que pase pregunta si al que esta apuntando es otro nodo con informacion
        // o solamente ya es el final de la lista
        while(currentNode.getNext() != null){ 

            // en cada iteracion se actualiza el nodo para que este pueda verificar por cada nodo enlazado
            currentNode = currentNode.getNext();
        }
        
        //cuando termina la iteracion simplemente se detecta que se llego al final de la lista
        //asi que se hace seguimiento al nuevo nodo.
        currentNode.setNext(new Node<E>(element));
        size++;
    }

    public E removeFirst(){ 

        if(isEmpty()) return null;

        E elementEliminated = head.getElement();

        head = head.getNext();
        size--;

        return elementEliminated;
    }

    //codigo para aprendisaje de porque no funciona.
    
    public E removeLastt(){

        if(isEmpty()) return null;

        Node<E> currentNode = head;

        while(currentNode.getNext() != null){
            currentNode = currentNode.getNext();
        }

        E elementEliminated = currentNode.getElement();
        currentNode = null;
        return elementEliminated;
    }

    public E removeLast(){

        E elementEliminated;

        if(isEmpty()) return null;

        if(head.getNext() == null){
            elementEliminated = head.getElement();
            head = null;
            return elementEliminated;
        }

        Node<E> currentNode = head;
        Node<E> beforeLastNode = currentNode;

        while(currentNode.getNext() != null){

            beforeLastNode = currentNode;
            currentNode = currentNode.getNext();
        }

        elementEliminated = currentNode.getElement();
        beforeLastNode.setNext(null);
        size--;
        return elementEliminated;
    }

    public static void main(String[] args){

    }
}
