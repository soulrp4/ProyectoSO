private void button4_Click(object sender, EventArgs e)
{
	string mensaje = "4/";
	
	byte[] msg = System.Text.Encoding.ASCII.GetBytes(mensaje);
	server.Send(msg);
	
	byte[] msg2 = new byte[80];
	server.Recieve(msg2);
	mensaje = Encoding.ASCII.GetString(msg2).Split('\0')[0];
	contLb1.Text  = mensaje;
}