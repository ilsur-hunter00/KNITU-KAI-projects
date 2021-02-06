package application;

import javafx.application.Platform;
import javafx.scene.control.Label;

public class MyThread implements Runnable{
	
	static Label label;
	
	@Override
	public void run() {
		try {
			Thread.sleep(2000);
			
			Platform.runLater(() -> {
				MyThread.label.setText(" ");
			});
			
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	MyThread(Label lb) {
		MyThread.label = lb;
		MyThread.label.setText("Объект создан");
	}

}
