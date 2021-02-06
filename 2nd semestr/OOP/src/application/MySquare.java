package application;

import javafx.scene.canvas.Canvas;
import javafx.scene.control.Alert;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.control.Label;

public class MySquare {

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
			gc.setFill(Color.RED);
			gc.fillRect(
					point.X-length/2, point.Y-length/2, this.length, this.length);
		}
		else {
			gc.setFill(Color.AQUAMARINE);
			gc.fillRect(point.X-length/2-1, point.Y-length/2-1, this.length+2, this.length+2);
		}
	}
	
	void checkBorder(double dx, double dy) {
		if (cnv.getWidth()-point.X < length/2) this.point.X -= dx;
		else if (point.X < length/2) this.point.X -= dx;
		else if (cnv.getHeight()-point.Y < length/2) this.point.Y -= dy;
		else if (point.Y < length/2) this.point.Y -= dy;
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
			gc.fillRect(point.X-length/2, point.Y-length/2, this.length, this.length);
		}
		else this.show(true);
	}
	
	boolean checkForResize(double L) {
		if ((cnv.getWidth()-point.X < L/2) || (point.X < L/2) || (cnv.getHeight()-point.Y < L/2) || (point.Y < L/2)) {
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
	
	MySquare(MyPoint Point, double l, Canvas cnv, GraphicsContext gc) {
		
		this.point = Point;
		this.length = l;
		this.cnv = cnv;
		this.gc = gc;
	}
	
	MySquare(MyPoint Point, double l, int c, int c0, Canvas cnv, GraphicsContext gc, Label lb) {
		
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
