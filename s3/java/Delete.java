import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/servlet/Delete")
public class Delete extends HttpServlet {

	public void service(HttpServletRequest req, HttpServletResponse res)
			throws ServletException, IOException {

		String param = req.getParameter("table");
		String cle = req.getParameter("cle");

		Statement stmt;
		String query = "";
		ResultSet rs;
		ResultSetMetaData rsm;
		String repo = "";
		PrintWriter out = res.getWriter();

		try {

			Connection con = null;

			Class.forName("org.postgresql.Driver");
			String url = "jdbc:postgresql://psqlserv/n3p1";
			String nom = "affolabp";
			String mdp = "moi";
			con = DriverManager.getConnection(url, nom, mdp);
			stmt = con.createStatement();
			query = "DELETE From " + param + " Where ID = " + cle;
			System.out.println(query);
			rs = stmt.executeQuery(query);

			con.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}