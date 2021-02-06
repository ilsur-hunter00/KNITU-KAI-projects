package application;

import javafx.scene.canvas.Canvas;
import javafx.scene.control.Alert;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.control.Label;

public class MyLine {

	MyPoint point;
	double length;
	int count;
	int count0;
	Label label;
	
	Canvas cnv;
	GraphicsContext gc;
	
	Alert alert;
	
	void doAlert(String text) {
		alert = new Alert(Alert.AlertType.INFORMATION);
		alert.setHeaderText(null);
		alert.setContentText(text);
		alert.showAndWait();
	}
	
	void show(boolean sh) {
		if (sh) {
			gc.setFill(Color.BLACK);
	        gc.fillRect(
					point.X-length/2, point.Y-2, this.length, 4);
		}
		else {
			gc.setFill(Color.AQUAMARINE);
			gc.fillRect(point.X-length/2-5, point.Y-2-5, this.length+10, 4+10);
		}
	}
	
	void checkBorder(double dx, double dy) {
		if (cnv.getWidth()-point.X < length/2) this.point.X -= dx;
		else if (point.X < length/2) this.point.X -= dx;
		else if (cnv.getHeight()-point.Y < 5) this.point.Y -= dy;
		else if (point.Y < 5) this.point.Y -= dy;
	}
	
	void moveTo(double dx, double dy) {
		this.show(false);
		point.X += dx;
		point.Y += dy;
		checkBorder(dx, dy);
		this.show(true);
	}
	
	void change(double p) {
		if (checkForResize(p)) {
			this.show(false);
			this.length = p;
			this.show(true);
		}
	}
	
	void delete() {
		this.show(false);
	}
	
	void ID(boolean t) {
		if (t) {
			gc.setFill(Color.CHARTREUSE);
			gc.fillRect(
					point.X-length/2, point.Y-2, this.length, 4);
		}
		else this.show(true);
	}
	
	boolean checkForResize(double L) {
		if ((cnv.getWidth()-point.X < L/2) || (point.X < L/2) || (cnv.getHeight()-point.Y < 5) || (point.Y < 5)) {
			doAlert("Изменения невозможны, фигура выходит за рамки поля!");
			return false;
		}
		else return true;
	}
	
	void mythread() {
		MyThread mt = new MyThread(label);
		Thread newThread = new Thread(mt);
		newThread.start();
	}
	
	MyLine(MyPoint Point) {
		
		this.point = Point;
		this.length = 30;
		this.count = 0;
	}
	
	MyLine(MyPoint Point, double l, int c, int c0, Canvas cnv, GraphicsContext gc, Label lb) {
		
		this.point = Point;
		this.length = l;
		this.count = c;
		this.count0 = c0;
		this.cnv = cnv;
		this.gc = gc;
		this.label = lb;
		
		mythread();
	}
}
