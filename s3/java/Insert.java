import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;
import java.sql.*;

@WebServlet("/servlet/Insert")
public class Insert extends HttpServlet {

	public void service(HttpServletRequest req, HttpServletResponse res)
			throws ServletException, IOException {

		String param = req.getParameter("table");
		String id = req.getParameter("id");
		String name = req.getParameter("nom");
		String prenom = req.getParameter("prenom");

		Statement stmt;
		String query = "";
		ResultSet rs;
		ResultSetMetaData rsm;
		PrintWriter out = res.getWriter();

		try {

			Connection con = null;

			Class.forName("org.postgresql.Driver");
			String url = "jdbc:postgresql://psqlserv/n3p1";
			String nom = "affolabp";
			String mdp = "moi";
			con = DriverManager.getConnection(url, nom, mdp);
			stmt = con.createStatement();
			if (param != null)
				query = "Insert into " + param + " values (" + id + ", '" + name
						+ "', '" + prenom + "')";
			else
				query = "Insert into personne values (" + id + ", '" + name + "', '" + prenom + "')";
			System.out.println(query);
			rs = stmt.executeQuery(query);

			con.close();

		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}