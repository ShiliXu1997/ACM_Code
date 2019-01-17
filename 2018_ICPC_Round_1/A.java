//******************************************************************************
// File Name: A.java
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月30日 星期四 19时34分28秒
//******************************************************************************

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigDecimal a = sc.nextBigDecimal();
		BigDecimal b = sc.nextBigDecimal();
		BigInteger aa = a.scaleByPowerOfTen(15).toBigInteger();
		BigInteger bb = b.scaleByPowerOfTen(15).toBigInteger();
		BigInteger res = aa.subtract(bb.multiply(aa.divide(bb)));
		BigDecimal ans = new BigDecimal(res.toString()).scaleByPowerOfTen(-15);
		System.out.println(ans);
	}
}
