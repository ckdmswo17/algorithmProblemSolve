// 그냥 백준 문제 : 문자열 반복

import java.util.*;

public class StringRepeat {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int length = sc.nextInt();
		String[] word = new String[length];
		int[] repeat  = new int[length];
		
		for(int i=0;i<length;i++) {
			repeat[i] = sc.nextInt();
			word[i] = sc.next();
		}
		
		for(int i=0;i<length;i++) {
			for(int j=0;j<word[i].length();j++) {
				char c = word[i].charAt(j);
				for(int z=0;z<repeat[i];z++) {
					System.out.print(c);
				}
			}
			if(i != length-1) {
				System.out.println();
			}
		}
		sc.close();
	}
}