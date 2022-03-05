import java.util.*;

class Node{
	String name;
	ArrayList<Node> children;

	public Node(String name){
		this.name = name;
		children = new ArrayList<Node>();
	}
}

class Catalog{
	HashMap<String,Node> hm;
	Set<String> items;

	public Catalog(){
		hm = new HashMap<> () ;
		items = new HashSet<String>();
	}

	public void createMap(String parent,String child){
		Node p;
		if(hm.containsKey(parent)){
			p = hm.get(parent);

		}
		else{
			p = new Node(parent);
			hm.put(parent,p);
			items.add(parent);
		}

		if(items.contains(child)){
			items.remove(child);
		}
		Node c;
		
		if(hm.containsKey(child)){
			c = hm.get(child);	
		}
		else{
			c = new Node(child);
			hm.put(child,c);
		}
		p.children.add(c);
	}

	public void printForest(){
		for(String root : items){
			System.out.println(root);
			printTree(hm.get(root),1);
		}
	}

	public void printTree(Node root,int tab){
		for(Node child : root.children){
			for(int i=0;i<tab;i++){
				System.out.print(" ");
			}
			System.out.println(child.name);
			printTree(child,tab+1);
		}
	}


	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		Catalog ans = new Catalog();
		while(n-- > 0){
			String parent = s.next();
			String child = s.next();
			ans.createMap(parent, child);
		}
		s.close();
		ans.printForest();
	}
}