import java.io.*;
import java.rmi.ServerException;
import java.sql.*;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/servlet/Lister")
public class Lister extends HttpServlet {

	public void service(HttpServletRequest req, HttpServletResponse res)
			throws ServletException, IOException {

		String param = req.getParameter("table");

		Statement stmt;
		String query;
		ResultSet rs;
		ResultSetMetaData rsm;
		PrintWriter out = res.getWriter();
		res.setContentType("text/html");

		out.println(" <!Doctype html>");
		out.println(" <html lang=\"en\">");
		out.println(" <head><meta charset=\"utf-8\">");
		out.println(" <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">");
		out.println(" <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> ");
		out.println(" <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css\">");
		out.println(" <style>tr:hover>td background-color:black</style>");
		out.println(" <title>Ca marche</title></head><body><center>");

		try {

			Connection con = null;

			Class.forName("org.postgresql.Driver");
			String url = "jdbc:postgresql://psqlserv/n3p1";
			String nom = "affolabp";
			String mdp = "moi";
			con = DriverManager.getConnection(url, nom, mdp);
			stmt = con.createStatement();

			if (param == null)
				query = "select * from personne";
			else 
				query = "Select * from " + param;
			rs = stmt.executeQuery(query);
			rsm = rs.getMetaData();
			
			int i;
			int columnCount = rsm.getColumnCount();	
			
			out.println("<form method =\"get\" action= \"http://localhost:8080/vide/servlet/Insert?table=personne\">");
			out.println("<p><input type = \"number\" name=\"id\" /></p>");
			out.println("<p><input type = \"text\" name =\"nom\" /></p>");
			out.println("<p><input type = \"text\" name =\"prenom\" /></p>");
			out.println("<p><input type= submit value=Envoyer /></p>");
			out.print("</form>");
			
			out.println( "<table class=\"table-centered table-hover table-condensed\">");
			while (rs.next()) {
				String n = rs.getString("nom");
				// System.out.println(n);
				out.println("<table>");
				out.println("<form>");
				out.println("<tr>");
				out.println("<td>" + rs.getString(1) + "</td><p>   </p><td>&nbsp</td>");
				for (i = 2; i < 4; i++) {
					out.println("<td>");
					out.println("<input style=\"margin-right:5px\" type=\"text\" name=\"" + rsm.getColumnName(i) + "\" value=" + rs.getString(i) + ">");
					out.println("</td>");
				}
				out.println("</tr>");
				out.println("</form>");
				out.println("</table>");
			}
			con.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}