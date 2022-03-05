public class Parent{
    int m(){
        System.out.println("parent");
    }
}

public class child extends Parent{
    int m(){
        System.out.println("child");
    }
}


class temp1{

    public static void main(String[] args){
        Parent p = new Child();
        p.m();
    }
}