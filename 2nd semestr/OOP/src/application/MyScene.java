package application;

import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class MyScene {
	
	Canvas cnv;
	GraphicsContext gc;
	Label lbl1, lbl2, lbl3, lbl4;
    TextField tf1;
    Button btn1, btn2, btn3;
    CheckBox checkBox;
    ChoiceBox<String> choiceBox;
    Rectangle rect; 
    Scene scene;
	
	//
    
    void function() {
    	
    	this.gc.setFill(Color.AQUAMARINE);  
    	this.gc.fillRect(0,0,1000,1000);
        
    	this.tf1.setPrefColumnCount(5);
        
    	this.choiceBox.setValue("Круг");
        
    	this.checkBox.setSelected(false);
        
    	this.rect.setWidth(200);
    	this.rect.setHeight(100);
    	this.rect.setFill(Color.BISQUE);
        
        FlowPane.setMargin(this.cnv, new Insets(20,0,0,20)); 
        FlowPane.setMargin(this.choiceBox, new Insets(-400,0,0,60)); 
        FlowPane.setMargin(this.btn1, new Insets(-400,0,0,15)); 
        FlowPane.setMargin(this.btn2, new Insets(-250,0,0,-150));
        FlowPane.setMargin(this.lbl4, new Insets(-700,0,0, 1040));
        FlowPane.setMargin(this.lbl1, new Insets(-560,0,0,1085)); 
        FlowPane.setMargin(this.tf1, new Insets(-560,0,0,1150)); 
        FlowPane.setMargin(this.checkBox, new Insets(-480,0,0,1085)); 
        FlowPane.setMargin(this.lbl2, new Insets(-480,0,0,0)); 
        FlowPane.setMargin(this.btn3, new Insets(-400,0,0,1085)); 
        FlowPane.setMargin(this.rect, new Insets(-150,0,0,1085)); 
        FlowPane.setMargin(this.lbl3, new Insets(-150,0,0,1150)); 
      
    }	
    
    MyScene(Canvas cnv, GraphicsContext gc, Label lbl1, Label lbl2, Label lbl3, TextField tf1, Button btn1, Button btn2, Button btn3, 
    		Label lbl4, ChoiceBox<String> choiceBox, CheckBox checkBox, Rectangle rect, Scene scene) {
    	
    	this.cnv = cnv;
    	this.gc = gc;
    	this.lbl1 = lbl1;
    	this.lbl2 = lbl2;
    	this.lbl3 = lbl3;
    	this.lbl4 = lbl4;
    	this.tf1 = tf1;
    	this.btn1 = btn1;
    	this.btn2 = btn2;
    	this.btn3 = btn3;
    	this.checkBox = checkBox;
    	this.choiceBox = choiceBox;
    	this.scene = scene;
    	this.rect = rect;
    	
    	function();
    	
    }
}
