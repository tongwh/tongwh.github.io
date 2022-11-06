function runge
%
%%%%%%%%%%%%%%%%%%%%% xi and yi function declaration
%
xi=inline('-1+(2*(x-1)/n)'); %when call argnames(xi) it will shows arg are x, n
                             %so when evaluate value for xi need to
                             %arguments xi(n,x)
yi=inline('1/(1+25*(x^2))');

%
%%%%%%%%%%%%%% plot Runge Function
%
axis([-1 1 -1 2]);  %to print x and y axis maximum value
numX=100;           %the maximum point for drawing runge function curve
for i=1:numX        %to draw curve for runge function with 100 points
        xValue(i)=xi(numX-1,i);
        yValue(i)=yi(xValue(i));
end
plot(xValue,yValue,'r','linewidth',2)
text(0.1,0.9,'Runge function','color','r')
hold on 
xValue=0; yValue=0;

%
%%%%%%%%%%%%%% polynomial fitting interpolating
%
for numPoint=2:5
    n=2*numPoint;   %starting from 2 points
    f=0; xValue=0; yValue=0;
    for i=1:n
        xValue(i)=xi(n-1,i);    %where n-1 is for xi(n) and i for xi(x)
        yValue(i)=yi(xValue(i));
    end
    p=polyfit(xValue,yValue,n-1);
    x=[-1:0.00001:1];
    f=polyval(p,x);
    % special drawing for 5 and 9 times polynomial
    switch(numPoint)
        case 3  %5th-order interpolating polynomial
            plot(x,f,'b','linewidth',2)
            text(0.4,0.4,{'5th-order interpolating',' polynomial'},'color','b')
            continue
        case 5  %9th-order interpolating polynomial
            plot(x,f,'g','linewidth',2) 
            text(-0.85,-0.2,'9th-order interpolating polynomial','color','g')
            continue
    end
    plot(x,f,'k','linewidth',1)
end
title('Runge Phenomenon')
hold off