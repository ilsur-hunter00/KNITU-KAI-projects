package application;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.KeyCode;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
  
public class Main extends Application{
	
	Canvas cnv = new Canvas(1000, 570);			//canvas
	GraphicsContext gc = cnv.getGraphicsContext2D();
	
	Label lbl1 = new Label("�������: ");	
    Label lbl2 = new Label("'����'");
    Label lbl3 = new Label("        Hello!");
    Label lbl4 = new Label("��� ����������� ����� ����������� ������ W,A,S,D.");
    TextField tf1 = new TextField();		
    Button btn1 = new Button("�������");	
    Button btn2 = new Button("�������");	
    Button btn3 = new Button("��������");
    CheckBox checkBox = new CheckBox("��������� ��� ���� ����� ");	 
    ObservableList<String> langs = FXCollections.observableArrayList("����", "�������", "�������", "������", "������"); 	//choice box
    ChoiceBox<String> choiceBox = new ChoiceBox<String>(langs);
	Rectangle rect = new Rectangle();
  
    FlowPane root = new FlowPane(cnv, choiceBox, btn1, btn2, lbl4, lbl1, tf1, checkBox, lbl2, btn3, rect, lbl3);
    Scene scene = new Scene(root);		
     
	int id = -1, count0 = -1;
	int count1 = -1, count2 = -1, count3 = -1, count4 = -1, count5 = -1;
    int flag = 1;
    
    double parametr;
    double dx = 0, dy = 0;
    double d = 40, l = 40;
    double border = 30;
    
    static MyCircle[] mycircle = new MyCircle[100];
    static MySquare[] mysquare = new MySquare[100];
    static MyLine[] myline = new MyLine[100];
    static MyRing[] myring = new MyRing[100];
    static DescribedSquare[] descr = new DescribedSquare[100];
    static MyPoint[] mypoint = new MyPoint[500];
    
    public static void main(String[] args) {
          
        Application.launch(args);
    }
    
    void redraw() {
    	for (int i = 0; i <= count1; i++) 
    		mycircle[i].show(true);
    	for (int i = 0; i <= count2; i++) 
    		mysquare[i].show(true);
    	for (int i = 0; i <= count3; i++) 
    		myline[i].show(true);
    	for (int i = 0; i <= count4; i++) 
    		myring[i].show(true);
    	for (int i = 0; i <= count5; i++) 
    		descr[i].show(true);
    	
    	switch (flag) {
    	case 1:
        	mycircle[id].ID(true);
    		break;
    	case 2:
    		mysquare[id].ID(true);
    		break;
    	case 3:
    		myline[id].ID(true);
    		break;
    	case 4:
    		myring[id].ID(true);
    		break;
    	case 5:
    		descr[id].ID(true);
    		break;
    	}
    }
    
    void deleteObject() {
    	
    	switch (flag) {
    	case 1:
    		mycircle[id].delete();
    		for (int i = id; i < count1; i++) {
    			mycircle[i] = mycircle[i+1];
    			mycircle[i].count --;
    		}
    		count1 --;
    		break;
    	case 2:
    		mysquare[id].delete();
    		for (int i = id; i < count2; i++) {
    			mysquare[i] = mysquare[i+1];
    			mysquare[i].count --;
    		}
    		count2 --;
    		break;
    	case 3:
    		myline[id].delete();
    		for (int i = id; i < count3; i++) {
    			myline[i] = myline[i+1];
    			myline[i].count --;
    		}
    		count3 --;
    		break;
    	case 4:
    		myring[id].delete();
    		for (int i = id; i < count4; i++) {
    			myring[i] = myring[i+1];
    			myring[i].count --;
    		}
    		count4 --;
    		break;
    	case 5:
    		descr[id].delete();
    		for (int i = id; i < count5; i++) {
    			descr[i] = descr[i+1];
    			descr[i].count --;
    		}
    		count5 --;
    		break;
    	}
    	
    	id = -1;
    }
      
    void getIndex(double x0, double y0) {
    	
    	double x1, y1, r1, l1;
    	boolean changeId = false;
    	
    	for (int j = count1; j >= 0; j--) {
    		x1 = mycircle[j].point.X;
    		y1 = mycircle[j].point.Y;
    		r1 = mycircle[j].radius;
    		if ((Math.pow(x1-x0, 2)+Math.pow(y1-y0, 2) <= r1*r1) && !changeId)
    			{
    				flag = 1;
    				id = j;
    				changeId = true;
    				mycircle[j].ID(true);
    				lbl1.setText("�������: ");
    	    		lbl2.setText("'����'");
    			}
    		else mycircle[j].ID(false);
    	}
    	
    	for (int j = 0; j <= count2; j++) {
    		x1 = mysquare[j].point.X;
    		y1 = mysquare[j].point.Y;
    		l1 = mysquare[j].length;
    		if ((x0-l1/2<x1) && (x1<x0+l1/2) && (y0-l1/2<y1) && (y1<y0+l1/2) && !changeId) 
    			{
    				flag = 2;
    				id = j;
    				changeId = true;
    				mysquare[j].ID(true);
    	    		lbl1.setText("�����: ");
    	    		lbl2.setText("'�������'");
    			}
    		else mysquare[j].ID(false);
    	}
    	
    	for (int j = 0; j <= count3; j++) {
    		x1 = myline[j].point.X;
    		y1 = myline[j].point.Y;
    		l1 = myline[j].length;
    		if ((x0-l1/2<x1) && (x1<x0+l1/2) && (y0-7<y1) && (y1<y0+7) && !changeId)
    			{
    				flag = 3;
    				id = j;
    				changeId = true;
    				myline[j].ID(true);
    	    		lbl1.setText("�����: ");
    	    		lbl2.setText("'�������'");
    			}
    		else myline[j].ID(false);
    	}
    	
    	for (int j = 0; j <= count4; j++) {
    		x1 = myring[j].point.X;
    		y1 = myring[j].point.Y;
    		r1 = myring[j].circle1.radius;
    		if (Math.pow(x1-x0, 2)+Math.pow(y1-y0, 2) <= r1*r1 && !changeId) 
    			{
    				flag = 4;
    				id = j;
    				changeId = true;
    				myring[j].ID(true);
    	    		lbl1.setText("�������: ");
    	    		lbl2.setText("'������'");
    			}
    		else myring[j].ID(false);
    	}
    	
    	for (int j = 0; j <= count5; j++) {
    		x1 = descr[j].point.X;
    		y1 = descr[j].point.Y;
    		l1 = descr[j].square.length;
    		if ((x0-l1/2<x1) && (x1<x0+l1/2) && (y0-l1/2<y1) && (y1<y0+l1/2) && !changeId) 
    			{
    				flag = 5;
    				id = j;
    				changeId = true;
    				descr[j].ID(true);
    	    		lbl1.setText("�����: ");
    	    		lbl2.setText("'������'");
    			}
    		else descr[j].ID(false);
    	}
    	
    	if (!changeId) id = -1;
    }
    
    void getChoiceBox(ChoiceBox<String> choiceBox) {
    	
    	if (choiceBox.getValue() == "����") {
    		flag = 1;
    		lbl1.setText("�������: ");
    		lbl2.setText("'����'");
    	}
    	else if (choiceBox.getValue() == "�������") {
    		flag = 2;
    		lbl1.setText("�����: ");
    		lbl2.setText("'�������'");
    	}
    	else if (choiceBox.getValue() == "�������") {
    		flag = 3;
    		lbl1.setText("�����: ");
    		lbl2.setText("'�������'");
    	}
    	else if (choiceBox.getValue() == "������") {
    		flag = 4;
    		lbl1.setText("�������: ");
    		lbl2.setText("'������'");
    	}
    	else if (choiceBox.getValue() == "������") {
    		flag = 5;
    		lbl1.setText("�����: ");
    		lbl2.setText("'������'");
    	}
    }
    
    void createObject() {
    	
    	switch(flag) {
		case 1:
			count1 ++; count0 ++;
			mypoint[count0] = new MyPoint(
					Math.random() * (cnv.getWidth()-2*(border+d/2)) + (border + d/2),
					Math.random() * (cnv.getHeight()-2*(border + d/2)) + (border + d/2));
			mycircle[count1] = new MyCircle(
					mypoint[count0], d/2, count1, count0, cnv, gc, lbl3);	
			mycircle[count1].show(true);
        	
			break;
		case 2:
            count2 ++; count0 ++;
			mypoint[count0] = new MyPoint(
					Math.random() * (cnv.getWidth()-2*(border + l/2)) + (border + l/2), Math.random() * (cnv.getHeight()-2*(border + l/2)) + (border + l/2));
			mysquare[count2] = new MySquare(mypoint[count0], l, count2, count0, cnv, gc, lbl3);
			mysquare[count2].show(true);
			break;
		case 3:
            count3 ++; count0 ++;
			mypoint[count0] = new MyPoint(
					Math.random() * (cnv.getWidth()-2*(border + l/2)) + (border + l/2), Math.random() * (cnv.getHeight()-2*(border + l/2)) + (border + l/2));
			myline[count3] = new MyLine(mypoint[count0], l, count3, count0, cnv, gc, lbl3);
			myline[count3].show(true);
			break;
		case 4:
            count4 ++; count0 ++;
			mypoint[count0] = new MyPoint(
					Math.random() * (cnv.getWidth()-2*(border+d/2)) + (border+d/2), Math.random() * (cnv.getHeight()-2*(border+d/2)) + (border+d/2));
			MyCircle mycircle1 = new MyCircle(mypoint[count0], d/2+5, cnv, gc);
			MyCircle mycircle2 = new MyCircle(mypoint[count0], d/2, cnv, gc);
			myring[count4] = new MyRing(mypoint[count0], mycircle1, mycircle2, count4, count0, cnv, gc, lbl3);
			myring[count4].show(true);
			break;
		case 5:
			count5 ++; count0 ++;
			mypoint[count0] = new MyPoint(
					Math.random() * (cnv.getWidth()-2*(border + l/2)) + (border + l/2), Math.random() * (cnv.getHeight()-2*(border + l/2)) + (border + l/2));
			MySquare mysquare = new MySquare(mypoint[count0], d/2+13, cnv, gc);
			mysquare.show(true);
			MyCircle mycircle = new MyCircle(mypoint[count0], d/2, cnv, gc);
			descr[count5] = new DescribedSquare(mypoint[count0], mysquare, mycircle, count5, count0, cnv, gc, lbl3);
			descr[count5].show(true);
            break;
    	}
    }
    
    void resize(CheckBox checkBox) {
    		
    	switch(flag) {
		case 1:
			if (checkBox.isSelected()) 
				for (int i = 0; i <= count1; i++)
					mycircle[i].change(parametr);
			else 
				mycircle[id].change(parametr);
			break;
		case 2:
			if (checkBox.isSelected()) 
				for (int i = 0; i <= count2; i++)
					mysquare[i].change(parametr);
			else 
				mysquare[id].change(parametr);
			break;
		case 3:
			if (checkBox.isSelected()) 
				for (int i = 0; i <= count3; i++)
					myline[i].change(parametr);
			else 
				myline[id].change(parametr);
			break;
		case 4:
			if (checkBox.isSelected()) 
				for (int i = 0; i <= count4; i++)
					myring[i].change(parametr);
			else 
				myring[id].change(parametr);
			break;
		case 5:
			if (checkBox.isSelected()) 
				for (int i = 0; i <= count5; i++)
					descr[i].change(parametr);
			else 
				descr[id].change(parametr);
			break;
	}	
    }
    
    void toMove(KeyCode key) {
    	
    	if (key == KeyCode.W) {
    		dx = 0;
    		dy = -5;
    	}
    	else if (key == KeyCode.S) {
    		dx = 0;
    		dy = 5;
    	}
    	else if (key == KeyCode.A) {
    		dx = -5;
    		dy = 0;
    	}
    	else if (key == KeyCode.D) {
    		dx = 5;
    		dy = 0;
    	}
    	
    	switch(flag) {
		case 1:
			mycircle[id].moveTo(dx, dy);
			break;
		case 2:
			mysquare[id].moveTo(dx, dy);
			break;
		case 3:
			myline[id].moveTo(dx, dy);
			break;
		case 4:
			myring[id].moveTo(dx, dy);
			break;
		case 5:
			descr[id].moveTo(dx, dy);
			break;
    	}	
    	
    	redraw();
    }
    
    @Override
    public void start(Stage stage) throws Exception {
        
        choiceBox.setOnAction(event -> {			//choice box action
        	getChoiceBox(choiceBox);
        }); 
        
        btn1.setOnAction(new EventHandler<ActionEvent>() {  	//button1 {Create}
            @Override
            public void handle(ActionEvent event) {
            	createObject();
            }
        });
        
        cnv.setOnMouseClicked(new EventHandler<MouseEvent>() {		//mouse event
            @Override
            public void handle(MouseEvent event) {
                getIndex(event.getX(),event.getY());
            }
        });
        
        btn2.setOnAction(new EventHandler<ActionEvent>() {   	//button2 {Delete}
            @Override
            public void handle(ActionEvent event) {
				//id = Integer.parseInt(tf1.getText());
				deleteObject(); 
            	redraw();
            }
        });
        
        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {	// {Move}
        	@Override
        		public void handle(KeyEvent event) {
        			if (id > -1) {
        				KeyCode key = event.getCode();
        				toMove(key);
        			}
        		}
        });  
        		
        btn3.setOnAction(new EventHandler<ActionEvent>() {  	//button3 {Resize}
            @Override
            public void handle(ActionEvent event) {
            	parametr = Double.parseDouble(tf1.getText());
            	resize(checkBox);
            	redraw();
            }
        });
          
        new MyScene(cnv, gc, lbl1, lbl2, lbl3, tf1, btn1, btn2, btn3, lbl4, choiceBox, checkBox, rect, scene);
        
        stage.setScene(scene);   
        stage.setTitle("OOP #1");
        stage.setWidth(1370);
        stage.setHeight(650);
        stage.show();
    }       
}
