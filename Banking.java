package bank;
import java.util.Scanner;
import java.lang.Math;
interface Bank
{
	void fixedDeposit();
	void currentAccount();
	void savingsAccount();
}
abstract class Fixed implements Bank
{
	public void fixedDeposit()
	{
		System.out.println("Fixed Deposit =>");
		System.out.println("Enter the amount you want to deposit :");
		Scanner s=new Scanner(System.in);
		double fd=s.nextDouble();
		System.out.println("\nThe amount deposited is :"+fd);
		System.out.println("Select the following duration of Fixed Deposit and Rate of interest :");
		System.out.print("\nDuration and Time :\n1.3 years and 7.25% interest.\n2.5 years and 7.50 % interest.\n3.7 years and 8 % interest.\nEnter your choice :");
		int choice=s.nextInt();
		switch(choice)
		{
			case 1:
				FDIntCalc(fd,3,0.0725);
				break;
			case 2:
				FDIntCalc(fd,5,0.075);
				break;
			case 3:
				FDIntCalc(fd,7,0.08);
				break;
			default:
				System.out.println("Invalid Choice!!");
				
		}
	}
	double FDIntCalc(double f,int time,double interest)
	{
		double principal=f;
		double maturityAmt;
		int quarterly=4; //number of times the interest will be compounding
		
		double A=(1+(interest/quarterly));
		double N=quarterly*time;
		
		maturityAmt=principal*Math.pow(A,N);
		
		System.out.println("The Maturity Amount after the period of time will be :"+maturityAmt);
		
		double intP=maturityAmt-principal;
		
		System.out.println("The compund interest acquired will be :"+intP);
		return 0;
	}
}
abstract class Savings extends Fixed
{
	Scanner s=new Scanner(System.in);
	public void savingsAccount()
	{
		System.out.println("Savings Account =>");
		System.out.println("Savings account comes with a compound interest of 3.5 %.");
		System.out.println("\nEnter the amount you want to deposit :");
		double sav=s.nextDouble();
		System.out.println("\nThe amount deposited is :"+sav);
		System.out.println("\nEnter the duration for which you want to calculate interest (in years) :");
		int t=s.nextInt();
		SavIntCalc(sav,t,0.035);
		double s1=AddMoney(sav);
		System.out.println("The amount after adding money with interest after "+t+" is :"+s1);
		SavIntCalc(s1,t,0.035);
		double w=WithDrawMoney(s1);
		SavIntCalc(w,t,0.035);
	}
	void SavIntCalc(double saving,int tm,double inter)
	{
		double prinAmt=saving;
		double matAmt;
		double A=(1+(inter/12)); //compounded monthly
		double N=tm*12;
		
		matAmt=prinAmt*Math.pow(A,N);
		
		System.out.println("The Maturity Amount after the period of time will be :"+matAmt);
		
		double intP=matAmt-prinAmt;
		
		System.out.println("The compound interest acquired will be :"+intP);
	}
	double AddMoney(double s1)
	{
		System.out.println("\nEnter the amount to deposit :");
		double sav1=s.nextDouble();
		s1+=sav1;
		return s1;
	}
	double WithDrawMoney(double w)
	{
		System.out.println("\nEnter the amount to withdraw :");
		double w1=s.nextDouble();
		if(w1>w)
		{
			System.out.println("Withdrawal Ammount greater than current balance.");
			return w;
		}
		else
		{
			w-=w1;
			System.out.println("\nThe amount after withdrawing "+w1+" is :"+w);
		}
		if(w<5000)
		{
			System.out.println("The current balance is below the minimum balance required.");
			System.out.println("A fine of Rs.100 will be given for each month the balance remains below Rs.5000..");
		}
		return w;
	}
}
class Current extends Savings
{
	public void currentAccount()
	{
		System.out.println("Current Account =>\n");
		System.out.println("Checkbook facility is available for this type of account.");
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the balance of the account :");
		double curr=s.nextDouble();
		double current=AddMon(curr);
		double withdraw=WithDraw(curr);
		System.out.println("The current balance is : "+curr);
		System.out.println("The amount after depositing "+curr+" is:"+current);
	}
		double AddMon(double curr)
		{
			System.out.println("\nEnter the amount to deposit :");
			double curr1=s.nextDouble();
			curr+=curr1;
			return curr;
		}
		double WithDraw(double withd)
		{
			System.out.println("\nEnter the amount to withdraw :");
			double withd1=s.nextDouble();
			if(withd1>withd)
			{
				System.out.println("Withdrawal Ammount greater than current balance.");
				return withd;
			}
			else
			{
				withd-=withd1;
				System.out.println("\nThe amount after withdrawing "+withd1+" is :"+withd);
			}
			if(withd<10000)
			{
				withd-=withd1;
				System.out.println("The current balance is below the minimum balance required.");
				System.out.println("A fine of Rs.500 will be given for each month the balance remains below Rs.10000..");
			}
			return withd;
		}  
}
class Banking
{
	public static void main(String args[])
	{
		Current current=new Current();
		Savings saving=current;
		saving.fixedDeposit();
		saving.savingsAccount();
		current.currentAccount();
	}
}
