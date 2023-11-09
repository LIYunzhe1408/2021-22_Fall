function x = self_define_mean_filter(img_resize,n,height,width)
%拷贝一个副本用以获取不变的灰度值
img_salt_pepper_copy =img_resize;  
 a(1:n,1:n)=1;
for i=1:height  
    for j=1:width  
        %卷积运算
        convolution=img_salt_pepper_copy(i:i+(n-1),j:j+(n-1)).*a;  
        %求和,一次只能求出一列，所以两个sum
        s=sum(sum(convolution));                
        %将均值赋值给中心像素点
       img_resize(i+(n-1)/2,j+(n-1)/2)=s/(n*n); 
    end  
end  
%通过unit8将矩阵转为图像——搜索得到的结论
img_resize=uint8(img_resize((n-1)/2+1:height+(n-1)/2,(n-1)/2+1:width+(n-1)/2));
x = img_resize;



F2=fft2(im2double(img_resize)); %FFT
F2=fftshift(F2); %FFT频谱平移
F2 = abs(F2);
T2 = log(F2+1);

%subplot(3,2,1),imshow(img_resize), title('mean_freq');
%subplot(3,2,2),imshow(T2,[]), title('mean_freq');
end