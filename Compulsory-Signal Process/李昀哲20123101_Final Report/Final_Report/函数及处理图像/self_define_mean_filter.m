function x = self_define_mean_filter(img_resize,n,height,width)
%����һ���������Ի�ȡ����ĻҶ�ֵ
img_salt_pepper_copy =img_resize;  
 a(1:n,1:n)=1;
for i=1:height  
    for j=1:width  
        %�������
        convolution=img_salt_pepper_copy(i:i+(n-1),j:j+(n-1)).*a;  
        %���,һ��ֻ�����һ�У���������sum
        s=sum(sum(convolution));                
        %����ֵ��ֵ���������ص�
       img_resize(i+(n-1)/2,j+(n-1)/2)=s/(n*n); 
    end  
end  
%ͨ��unit8������תΪͼ�񡪡������õ��Ľ���
img_resize=uint8(img_resize((n-1)/2+1:height+(n-1)/2,(n-1)/2+1:width+(n-1)/2));
x = img_resize;



F2=fft2(im2double(img_resize)); %FFT
F2=fftshift(F2); %FFTƵ��ƽ��
F2 = abs(F2);
T2 = log(F2+1);

%subplot(3,2,1),imshow(img_resize), title('mean_freq');
%subplot(3,2,2),imshow(T2,[]), title('mean_freq');
end