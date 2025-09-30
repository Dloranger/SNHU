import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.Color;

public class SlideShow extends JFrame {

	//Declare Variables
	private JPanel slidePane;
	private JPanel textPane;
	private JPanel buttonPane;
	private CardLayout card;
	private CardLayout cardText;
	private JButton btnPrev;
	private JButton btnNext;
	private JLabel lblSlide;
	private JLabel lblTextArea;
	
	//DL 2025-Sept-30 - Creating temperory hardcoded array that will be replaced by database later
	//Small 2D array to keep details for items together based on index
	//[0] - index [1] - picture [2] Short text [3] - image source
	private String[][] Packages;
	

	/**
	 * Create the application.
	 */
	public SlideShow() throws HeadlessException {
		initComponent();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initComponent() {
		
		//DL 2025-Sept-30 - Creating temporary hardcoded array that will be replaced by database later
		//Small 2D array to keep details for items together based on index
		//[0] - index [1] - picture [2] Short text [3] - image source
		Packages = new String [5][4];
		Packages[0][0] = "1";
		Packages[0][1] = "/resources/Spa1.jpg";
		Packages[0][2] = "The Omni Grove Park Inn";
		Packages[0][3] = "https://www.omnihotels.com/blog/wp-content/uploads/2017/04/1000x700_gpirst_spa_pool.jpg";
		
		Packages[1][0] = "2";
		Packages[1][1] = "/resources/Spa2.jpg";
		Packages[1][2] = "Omni Scottsdale Resort & Spa at Montelucia";
		Packages[1][3] = "https://www.omnihotels.com/blog/wp-content/uploads/2021/06/JoyofPurif_horizontal_large-blog.jpg";
		
		Packages[2][0] = "3";
		Packages[2][1] = "/resources/Spa3.jpg";
		Packages[2][2] = "Aura Spa at Le Blanc Spa Resort Los Cabos";
		Packages[2][3] = "https://secure.s.forbestravelguide.com/img/properties/blanc-spa-los-cabos/extra-large/le-blanc-spa-resort-los-cabos-hydrotherapy3.jpg";
		
		Packages[3][0] = "4";
		Packages[3][1] = "/resources/Spa4.jpg";
		Packages[3][2] = "Vista Encantada Spa Resort, Cabo San Lucas";
		Packages[3][3] = "https://vistaencantadaresort.com/images/home/amenities.jpg";
		
		Packages[4][0] = "5";
		Packages[4][1] = "/resources/Spa5.jpg";
		Packages[4][2] = "Mirror Lake Inn Resort & Spa, Lake Placid";
		Packages[4][3] = "https://assets.simpleviewinc.com/simpleview/image/upload/c_fill,h_348,q_75,w_618/v1/clients/newyorkstate/mirrorlakeinnspa_Instagram_2829_ig_18294539065046082_a9a7d54d-f001-44a8-9418-9d6b833a3828.jpg";
		//DL 2025-Sept-30 - Creating temporary hardcoded array that will be replaced by database later
		//Small 2D array to keep details for items together based on index
		//[0] - index [1] - picture [2] Short text [3] - image source
		
		
		
		//Initialize variables to empty objects
		card = new CardLayout();
		cardText = new CardLayout();
		slidePane = new JPanel();
		textPane = new JPanel();
		textPane.setBackground(Color.BLUE);
		textPane.setBounds(5, 470, 790, 50);
		textPane.setVisible(true);
		buttonPane = new JPanel();
		btnPrev = new JButton();
		btnNext = new JButton();
		lblSlide = new JLabel();
		lblTextArea = new JLabel();

		//Setup frame attributes
		setSize(800, 600);
		setLocationRelativeTo(null);
		setTitle("Top 5 Destinations SlideShow");
		getContentPane().setLayout(new BorderLayout(10, 50));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		//Setting the layouts for the panels
		slidePane.setLayout(card);
		textPane.setLayout(cardText);
		
		

		
		
		
		
		
		//logic to add each of the slides and text
		for (int i = 1; i <= 5; i++) {
			lblSlide = new JLabel();
			lblTextArea = new JLabel();
			lblSlide.setText(getResizeIcon(i));
			lblTextArea.setText(getTextDescription(i));
			slidePane.add(lblSlide, "card" + i);
			textPane.add(lblTextArea, "cardText" + i);
		}

		getContentPane().add(slidePane, BorderLayout.CENTER);
		getContentPane().add(textPane, BorderLayout.SOUTH);

		buttonPane.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 10));

		btnPrev.setText("Previous");
		btnPrev.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				goPrevious();
			}
		});
		buttonPane.add(btnPrev);

		btnNext.setText("Next");
		btnNext.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				goNext();
			}
		});
		buttonPane.add(btnNext);

		getContentPane().add(buttonPane, BorderLayout.SOUTH);
	}

	/**
	 * Previous Button Functionality
	 */
	private void goPrevious() {
		card.previous(slidePane);
		cardText.previous(textPane);
	}
	
	/**
	 * Next Button Functionality
	 */
	private void goNext() {
		card.next(slidePane);
		cardText.next(textPane);
	}

	
	/**
	 * Method to get the images
	 */
	

	
	private String getResizeIcon(int i) {
		String image = ""; 
		

		//DL 2025-Sept-30 - Disabled nested if-else in preference of an indexed call that is easily expanded to a different size and variable
		//contents that could reside on an accessible database later.
/*		if (i==1){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/TestImage1.jpg") + "'</body></html>";
		} else if (i==2){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/TestImage2.jpg") + "'</body></html>";
		} else if (i==3){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/TestImage3.jpg") + "'</body></html>";
		} else if (i==4){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/TestImage4.jpg") + "'</body></html>";
		} else if (i==5){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/TestImage5.jpg") + "'</body></html>";
		}
*/
		//retrieve the desired image from the packages array based on the index value.  Assumes i is presented as a base 1 value vs base 0
		//based on the strawman provided code.
		image = "<html><body><img width= '800' height='500' src='" + getClass().getResource(""+Packages[i-1][1]+"") + "'</body></html>";
		
		return image;
	}
	
	/**
	 * Method to get the text values
	 */
	private String getTextDescription(int i) {
		String text = ""; 
		
		//DL 2025-Sept-30 - Disabled nested if-else in preference of an indexed call that is easily expanded to a different size and variable
		//contents that could reside on an accessible database later.
/*		if (i==1){
			text = "<html><body><font size='5'>#1 The Grand Canyon.</font> <br>Spectacular canyon views and hiking.</body></html>";
		} else if (i==2){
			text = "<html><body>#2 Top Destination</body></html>";
		} else if (i==3){
			text = "<html><body>#3 Top Destination</body></html>";
		} else if (i==4){
			text = "<html><body>#4 Top Destination</body></html>";
		} else if (i==5){
			text = "<html><body>#5 Top Destination</body></html>";
		}
*/
		//retrieve the desired short text from the packages array based on the index value.  Assumes i is presented as a base 1 value vs base 0
		//based on the strawman provided code.
		text = "<html><body><font size='5'>#" + Packages[i-1][0] + " " +Packages[i-1][2] + "</body></html>";
		return text;
	}
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {

			@Override
			public void run() {
				SlideShow ss = new SlideShow();
				ss.setVisible(true);
			}
		});
	}
}