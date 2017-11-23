/*
 * Utilities script
 */

function trim(s)
{
	var l=0; var r=s.length -1;
	while(l < s.length && (s[l] == ' ' || s[l] == '\n'))
	{	l++; }
	while(r > l && (s[r] == ' ' || s[r] == '\n'))
	{	r-=1;	}
	return s.substring(l, r+1);
}

function show_errs(divname,msgstring)
{
	if(divname.length<=0) return false;

	var divlayer;
	
	if(document.layers)
	{
		divlayer = document.layers[divname];
        if(!divlayer){return true;}
		divlayer.document.open();
		divlayer.document.write(msgstring);
		divlayer.document.close();
	}
	else
	if(document.all)
	{
		divlayer = document.all[divname];
        if(!divlayer){return true;}
		divlayer.innerHTML=msgstring;
	}
	else
	if(document.getElementById)
	{
		divlayer = document.getElementById(divname);
        if(!divlayer){return true;}
		divlayer.innerHTML =msgstring;
	}
	divlayer.style.visibility="visible";
	return false;	
}
