class superClass{
    public void method1(){

    }
}

class child extends superClass{
    // public void method1(){
    //     System.out.println(2);
    // }
}

class Test2{
    public void t(){
        child c = new child();
        c.method1();
    }
} 
