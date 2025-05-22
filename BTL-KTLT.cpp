#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct{
	int ngay;
	int thang;
	int nam;
}date;

typedef struct{
	int msSV;
	char tenSV[50];
	char nganhSV[50];
	int khoaSV;
	float diemGPA;
	date ngaySinhSV;
	char queQuanSV[50];
}sinhVien;

typedef struct node{
	sinhVien thongTinSV;
	struct node *next;
}node;

node* taoNode(sinhVien thongTinSV){
	node *nodeMoi = (node*)malloc(sizeof(node));
	if (nodeMoi == NULL){
		printf("Loi cap phat bo nho\n");
		exit(1);
	}
	nodeMoi->thongTinSV = thongTinSV;
	nodeMoi->next = NULL;
	return nodeMoi;
}

void themVaoHead(node **head, sinhVien thongTinSV){
	node *nodeMoi = taoNode(thongTinSV);
	nodeMoi->next = *head;
	*head = nodeMoi;
}

void ghiVaoFile(sinhVien thongTinSV){
    FILE *f = fopen("DanhSachSinhVien.txt", "a");

    if (f == NULL){
        printf("Khong the mo file!\n");
        return;
    }

    fprintf(f, "-\n");
    fprintf(f, "%s\n", thongTinSV.tenSV);
    fprintf(f, "%d\n", thongTinSV.msSV);
    fprintf(f, "%d %d %d\n", thongTinSV.ngaySinhSV.ngay, thongTinSV.ngaySinhSV.thang, thongTinSV.ngaySinhSV.nam);
    fprintf(f, "%s\n", thongTinSV.nganhSV);
    fprintf(f, "%d\n", thongTinSV.khoaSV);
    fprintf(f, "%.2f\n", thongTinSV.diemGPA);
    fprintf(f, "%s\n", thongTinSV.queQuanSV);


    fclose(f);
}

sinhVien nhapThongTinSV(){
	sinhVien thongTinSV;

	printf("Nhap ten: ");
	getchar();
	fgets(thongTinSV.tenSV, sizeof(thongTinSV.tenSV), stdin);
	thongTinSV.tenSV[strcspn(thongTinSV.tenSV, "\n")] = '\0';

	printf("Nhap ma so sinh vien: ");
	scanf("%d", &thongTinSV.msSV);
	getchar();

	printf("Nhap ten nganh: ");
	fgets(thongTinSV.nganhSV, sizeof(thongTinSV.nganhSV), stdin);
	thongTinSV.nganhSV[strcspn(thongTinSV.nganhSV, "\n")] = '\0';

	printf("Nhap khoa: ");
	scanf("%d", &thongTinSV.khoaSV);
	getchar();

	printf("Nhap que quan: ");
	fgets(thongTinSV.queQuanSV, sizeof(thongTinSV.queQuanSV), stdin);
	thongTinSV.queQuanSV[strcspn(thongTinSV.queQuanSV, "\n")] = '\0';

	printf("Nhap ngay sinh: \n");
	printf("+ ngay: ");
	scanf("%d", &thongTinSV.ngaySinhSV.ngay);
	printf("+ thang: ");
	scanf("%d", &thongTinSV.ngaySinhSV.thang);
	printf("+ nam: ");
	scanf("%d", &thongTinSV.ngaySinhSV.nam);

	printf("Nhap diem GPA: ");
	scanf("%f", &thongTinSV.diemGPA);

    ghiVaoFile(thongTinSV);

	return thongTinSV;
}

void taoKhoangCach(int x){
    for(int i = 1; i <= x; i++){
        printf(" ");
    }
}

void inSinhVien(node *head){
    printf("%s", head->thongTinSV.tenSV);
    taoKhoangCach(20 - strlen(head->thongTinSV.tenSV));
    printf("|");

    char msSV[15];
    sprintf(msSV, "%d", head->thongTinSV.msSV);
    printf("%d", head->thongTinSV.msSV);
    taoKhoangCach(15 - strlen(msSV));
    printf("|");

    if(head->thongTinSV.ngaySinhSV.ngay < 10){
        printf("%d%d", 0, head->thongTinSV.ngaySinhSV.ngay);
    } else {
        printf("%d", head->thongTinSV.ngaySinhSV.ngay);
    }
    printf("/");
    if(head->thongTinSV.ngaySinhSV.thang < 10){
        printf("%d%d", 0, head->thongTinSV.ngaySinhSV.thang);
    } else {
        printf("%d", head->thongTinSV.ngaySinhSV.thang);
    }
    printf("/");
    printf("%d", head->thongTinSV.ngaySinhSV.nam);
    taoKhoangCach(5);
    printf("|");

    printf("%s", head->thongTinSV.nganhSV);
    taoKhoangCach(15 - strlen(head->thongTinSV.nganhSV));
    printf("|");

    if(head->thongTinSV.khoaSV < 10){
        printf("%d%d", 0, head->thongTinSV.khoaSV);
    } else printf("%d", head->thongTinSV.khoaSV);
    taoKhoangCach(6);
    printf("|");


    printf("%.2f", head->thongTinSV.diemGPA);
    taoKhoangCach(4);
    printf("|");

    printf("%s", head->thongTinSV.queQuanSV);
}

void chuyenDLvaoHead(node **head){
    FILE *f2 = fopen("DanhSachSinhVien.txt", "r");
    sinhVien thongTinSV;
	char line[10];
    int a=1;
	while(a){
        if(fgets(line, sizeof(line), f2) != NULL && strcmp(line, "\n") != 0){
            fgets(thongTinSV.tenSV, sizeof(thongTinSV.tenSV), f2);
            thongTinSV.tenSV[strcspn(thongTinSV.tenSV, "\n")] = '\0';
            fscanf(f2, "%d", &thongTinSV.msSV);
            fscanf(f2, "%d %d %d", &thongTinSV.ngaySinhSV.ngay, &thongTinSV.ngaySinhSV.thang, &thongTinSV.ngaySinhSV.nam);
            fgetc(f2);
            fgets(thongTinSV.nganhSV, sizeof(thongTinSV.nganhSV), f2);
            thongTinSV.nganhSV[strcspn(thongTinSV.nganhSV, "\n")] = '\0';
            fscanf(f2, "%d", &thongTinSV.khoaSV);
            fscanf(f2, "%f", &thongTinSV.diemGPA);
            fgetc(f2);
            fgets(thongTinSV.queQuanSV, sizeof(thongTinSV.queQuanSV), f2);
            thongTinSV.queQuanSV[strcspn(thongTinSV.queQuanSV, "\n")] = '\0';

            themVaoHead(head, thongTinSV);


        } else {
            a = 0;
        }
	}

	fclose(f2);
}

void inDanhSach(node *head){
	FILE *f = fopen("DanhSachSinhVien.txt", "r");
	if (f == NULL){
		printf("Khong the mo file!\n");
		return;
	}
	fclose(f);

	if(head == NULL) chuyenDLvaoHead(&head);

    if(head == NULL){
        printf("Danh sach rong!\n");
    } else {
        printf("Ten                  MSSV            Ngay Sinh       Nganh           Khoa     GPA      Que Quan\n");
        while(head != NULL){
            inSinhVien(head);
            printf("\n");
            head = head->next;
        }
    }
}

void capNhatFile(node *head){
    FILE *f = fopen("DanhSachSinhVien.txt", "w");

    if (f == NULL){
        printf("Khong the mo file!\n");
        return;
    }

    while(head != NULL){
        fprintf(f, "-\n");
        fprintf(f, "%s\n", head->thongTinSV.tenSV);
        fprintf(f, "%d\n", head->thongTinSV.msSV);
        fprintf(f, "%d %d %d\n", head->thongTinSV.ngaySinhSV.ngay, head->thongTinSV.ngaySinhSV.thang, head->thongTinSV.ngaySinhSV.nam);
        fprintf(f, "%s\n", head->thongTinSV.nganhSV);
        fprintf(f, "%d\n", head->thongTinSV.khoaSV);
        fprintf(f, "%.2f\n", head->thongTinSV.diemGPA);
        fprintf(f, "%s\n", head->thongTinSV.queQuanSV);

        head = head->next;
    }

    fclose(f);
}

void xoaThongTinSV(node **head, int mssvXoa){
    chuyenDLvaoHead(&*head);
    node *phanTuXoa = *head;
    node *xoa = NULL;
    int daXoa = 0;
    if(*head == NULL){
        printf("Danh sach rong!\n");
        return;
    }
    //truong hop phan tu nam o dau
    if(phanTuXoa->thongTinSV.msSV == mssvXoa){
        *head = phanTuXoa->next;
        free(phanTuXoa);
        daXoa = 1;
    } else {
        while(phanTuXoa->next != NULL){
            if(phanTuXoa->next->thongTinSV.msSV == mssvXoa){
                xoa = phanTuXoa->next->next;
                free(phanTuXoa->next);
                phanTuXoa->next = xoa;
                daXoa = 1;
                break;
            }
            phanTuXoa = phanTuXoa->next;
        }
    }
    if(daXoa == 1){
        printf("Xoa thanh cong\n");
        capNhatFile(*head);
    } else {
        printf("MSSV khong co trong danh sach!\n");
    }
}

void timKiemTheoMSSV(node *head, int mssvCanTiem){
    chuyenDLvaoHead(&head);
    int daTim = 0;
    if(head == NULL){
        printf("Danh sach rong!\n");
        return;
    }

    while(head != NULL){
        if(head->thongTinSV.msSV == mssvCanTiem){
            printf("Ten                  MSSV            Ngay Sinh       Nganh           Khoa     GPA      Que Quan\n");
            inSinhVien(head);
            printf("\n");
            daTim = 1;
            break;
        }
        head = head->next;
    }

    if(daTim == 0) printf("Khong tim thay sinh vien!\n");
}

void timKiemTheoTenSV(node *head, char tenSVCanTim[50]){
    chuyenDLvaoHead(&head);
    int daTim = 0;
    if(head == NULL){
        printf("Danh sach rong!\n");
        return;
    }

    while(head != NULL){
        if(strcmp(head->thongTinSV.tenSV, tenSVCanTim) == 0){
            printf("Ten                  MSSV            Ngay Sinh       Nganh           Khoa     GPA      Que Quan\n");
            inSinhVien(head);
            printf("\n");
            daTim = 1;
            break;
        }
        head = head->next;
    }

    if(daTim == 0) printf("Khong tim thay sinh vien!\n");
}

// kiem tra nganh da co trong du lieu chua
int kiemTraNganh(char nganhCanKiemTra[50], int *soNganh, char nganh[50][50]){
    for(int i = 0; i < *soNganh; i++){
        if(strcmp(nganhCanKiemTra, nganh[i]) == 0) return 1;
    }
    return 0;
}

void inDanhSachTheoNganh(node *head, int *soNganh, char nganh[50][50]){
    FILE *f = fopen("DanhSachSinhVien.txt", "r");
	if (f == NULL){
		printf("Khong the mo file!\n");
		return;
	}
	fclose(f);

	if(head == NULL) chuyenDLvaoHead(&head);

	node *temp = head;

	if(head == NULL){
        printf("Danh sach rong!\n");
    } else {
        while(temp != NULL){
            if(*soNganh == 0){
                strcpy(nganh[*soNganh], temp->thongTinSV.nganhSV);
                (*soNganh)++;
            } else {
                if(!kiemTraNganh(temp->thongTinSV.nganhSV, soNganh, nganh)){
                    strcpy(nganh[*soNganh], temp->thongTinSV.nganhSV);
                    (*soNganh)++;
                }
            }
            temp = temp->next;
        }

        temp = head;
        for(int i = 0; i < *soNganh; i++){
            printf("Nganh: %s\n", nganh[i]);
            printf("Ten                  MSSV            Ngay Sinh       Nganh           Khoa     GPA      Que Quan\n");
            while(temp != NULL){
                if(strcmp(temp->thongTinSV.nganhSV, nganh[i]) == 0){
                    inSinhVien(temp);
                    printf("\n");
                }
                temp = temp->next;
            }
            temp = head;
        }
    }
}

void inDanhSachTheoGPA(node *head){
    FILE *f = fopen("DanhSachSinhVien.txt", "r");
	if (f == NULL){
		printf("Khong the mo file!\n");
		return;
	}
	fclose(f);

	if(head == NULL) chuyenDLvaoHead(&head);

	node *sapXepTheoGPA = head;

    if(head == NULL){
        printf("Danh sach rong!\n");
    } else {
        node *i, *j;
        for(i = sapXepTheoGPA; i->next != NULL; i = i->next){
            for(j = i->next; j != NULL; j = j->next){
                if (i->thongTinSV.diemGPA < j->thongTinSV.diemGPA) {
                    sinhVien temp = i->thongTinSV;
                    i->thongTinSV = j->thongTinSV;
                    j->thongTinSV = temp;
                }
            }
        }
        printf("Ten                  MSSV            Ngay Sinh       Nganh           Khoa     GPA      Que Quan\n");
        while(sapXepTheoGPA != NULL){
            inSinhVien(sapXepTheoGPA);
            printf("\n");
            sapXepTheoGPA = sapXepTheoGPA->next;
        }
    }
}

void chinhSuaThongTinSV(node **head, int msssCanChinhSua, int phepChon){
    FILE *f = fopen("DanhSachSinhVien.txt", "r");
	if (f == NULL){
		printf("Khong the mo file!\n");
		return;
	}
	fclose(f);

	if(*head == NULL) chuyenDLvaoHead(&*head);

	if(*head == NULL){
        printf("Danh sach rong!\n");
        return;
    }

    node *check = *head;
    switch(phepChon){
        case 1:{
            char tenSVnew[50];
            printf("Nhap ten sinh vien moi: ");
            getchar();
            fgets(tenSVnew, sizeof(tenSVnew), stdin);
            tenSVnew[strcspn(tenSVnew, "\n")] = 0;
            int daChinhSua = 0;

            while(check != NULL){
                if(check->thongTinSV.msSV == msssCanChinhSua){
                    strcpy(check->thongTinSV.tenSV, tenSVnew);
                    daChinhSua = 1;
                    printf("Chinh sua thanh cong\n");
                    capNhatFile(*head);
                    break;
                }
                check = check->next;
            }
            if(daChinhSua == 0) printf("Khong tim thay sinh vien!\n");

            check = *head;
            break;
        }

        case 2:{
            int msSVnew;
            printf("Nhap ma so sinh vien moi: ");
            scanf("%d", &msSVnew);
            int daChinhSua = 0;

            while(check != NULL){
                if(check->thongTinSV.msSV == msssCanChinhSua){
                    check->thongTinSV.msSV = msSVnew;
                    daChinhSua = 1;
                    printf("Chinh sua thanh cong\n");
                    capNhatFile(*head);
                    break;
                }
                check = check->next;
            }
            if(daChinhSua == 0) printf("Khong tim thay sinh vien!\n");

            check = *head;
            break;
        }

        case 3:{
            char nganhSVnew[50];
            printf("Nhap nganh moi: ");
            getchar();
            fgets(nganhSVnew, sizeof(nganhSVnew), stdin);
            nganhSVnew[strcspn(nganhSVnew, "\n")] = 0;
            int daChinhSua = 0;

            while(check != NULL){
                if(check->thongTinSV.msSV == msssCanChinhSua){
                    strcpy(check->thongTinSV.nganhSV, nganhSVnew);
                    daChinhSua = 1;
                    printf("Chinh sua thanh cong\n");
                    capNhatFile(*head);
                    break;
                }
                check = check->next;
            }
            if(daChinhSua == 0) printf("Khong tim thay sinh vien!\n");

            check = *head;
            break;
        }

        case 4:{
            int khoaSVnew;
            printf("Nhap khoa moi: ");
            scanf("%d", &khoaSVnew);
            int daChinhSua = 0;

            while(check != NULL){
                if(check->thongTinSV.msSV == msssCanChinhSua){
                    check->thongTinSV.khoaSV = khoaSVnew;
                    daChinhSua = 1;
                    printf("Chinh sua thanh cong\n");
                    capNhatFile(*head);
                    break;
                }
                check = check->next;
            }
            if(daChinhSua == 0) printf("Khong tim thay sinh vien!\n");

            check = *head;
            break;
        }

        case 5:{
            char queQuanSVnew[50];
            printf("Nhap que quan moi: ");
            getchar();
            fgets(queQuanSVnew, sizeof(queQuanSVnew), stdin);
            queQuanSVnew[strcspn(queQuanSVnew, "\n")] = 0;
            int daChinhSua = 0;

            while(check != NULL){
                if(check->thongTinSV.msSV == msssCanChinhSua){
                    strcpy(check->thongTinSV.queQuanSV, queQuanSVnew);
                    daChinhSua = 1;
                    printf("Chinh sua thanh cong\n");
                    capNhatFile(*head);
                    break;
                }
                check = check->next;
            }
            if(daChinhSua == 0) printf("Khong tim thay sinh vien!\n");

            check = *head;
            break;
        }

        case 6:{
            int ngayNew, thangNew, namNew;
            printf("Nhap ngay sinh moi:\n");
            printf("+ ngay: "); scanf("%d", &ngayNew);
            printf("+ thang: "); scanf("%d", &thangNew);
            printf("+ nam: "); scanf("%d", &namNew);

            int daChinhSua = 0;

            while(check != NULL){
                if(check->thongTinSV.msSV == msssCanChinhSua){
                    check->thongTinSV.ngaySinhSV.ngay = ngayNew;
                    check->thongTinSV.ngaySinhSV.thang = thangNew;
                    check->thongTinSV.ngaySinhSV.nam = namNew;
                    daChinhSua = 1;
                    printf("Chinh sua thanh cong\n");
                    capNhatFile(*head);
                    break;
                }
                check = check->next;
            }
            if(daChinhSua == 0) printf("Khong tim thay sinh vien!\n");

            check = *head;
            break;
        }

        case 7:{
            float diemGPAnew;
            printf("Nhap diem GPA moi: ");
            scanf("%f", &diemGPAnew);
            int daChinhSua = 0;

            while(check != NULL){
                if(check->thongTinSV.msSV == msssCanChinhSua){
                    check->thongTinSV.diemGPA = diemGPAnew;
                    daChinhSua = 1;
                    printf("Chinh sua thanh cong\n");
                    capNhatFile(*head);
                    break;
                }
                check = check->next;
            }
            if(daChinhSua == 0) printf("Khong tim thay sinh vien!\n");

            check = *head;
            break;
        }
    }
}

int MENU(){
	printf("---------------QUAN LY SINH VIEN---------------\n");
	printf("1. Them thong tin sinh vien\n");
	printf("2. Xoa thong tin sinh vien\n");
	printf("3. In danh sach thong tin sinh vien\n");
	printf("4. In danh sach thong tin sinh vien theo nganh\n");
    printf("5. In danh sach thong tin sinh vien theo diem gpa\n");
	printf("6. Chinh sua thong tin sinh vien\n");
	printf("7. Tim kiem sinh vien theo ma sinh vien\n");
	printf("8. Tim kiem sinh vien theo ten\n");
	printf("0. Thoat\n");
	printf("-----------------------------------------------\n");
	int luaChon;
	printf("Nhap: ");
	scanf("%d", &luaChon);
	return luaChon;
}

int MENUchinhSuaThongTin(){
    printf("-----------------------------------------------\n");
    printf("Chon thong tin muon chinh sua:\n");
	printf("1. Ten sinh vien\n");
	printf("2. Ma so sinh vien\n");
	printf("3. Nganh hoc\n");
	printf("4. Khoa\n");
    printf("5. Que quan\n");
	printf("6. Ngay sinh\n");
	printf("7. Diem GPA\n");
	printf("0. Thoat\n");
	int luaChonCSTT;
	printf("Chon: ");
	scanf("%d", &luaChonCSTT);
	return luaChonCSTT;
}

int main(){
	int luaChon = 1;
	int soNganh=0;
	char nganh[50][50];
	node *head = NULL;
	do{
		luaChon = MENU();
		switch(luaChon){
			case 1:{
				sinhVien sv = nhapThongTinSV();
				break;
			}
			case 2:{
			    int mssvXoa;
			    printf("Nhap mssv can xoa thong tin: ");
			    scanf("%d", &mssvXoa);
			    xoaThongTinSV(&head, mssvXoa);
				break;
			}
			case 3:{
				inDanhSach(head);
				break;
			}
			case 4:{
			    inDanhSachTheoNganh(head, &soNganh, nganh);
				break;
			}
			case 5:{
                inDanhSachTheoGPA(head);
				break;
			}
			case 6:{
			    int mssvCanChinhSua;
			    printf("Nhap mssv can chinh sua thong tin: ");
			    scanf("%d", &mssvCanChinhSua);
                int luaChonCSTT = MENUchinhSuaThongTin();
                while(luaChonCSTT!=0){
                    chinhSuaThongTinSV(&head, mssvCanChinhSua, luaChonCSTT);
                    luaChonCSTT = MENUchinhSuaThongTin();
                }
                break;
			}
			case 7:{
			    int mssvCanTim;
			    printf("Nhap mssv can tim: ");
			    scanf("%d", &mssvCanTim);
                timKiemTheoMSSV(head, mssvCanTim);
				break;
			}
			case 8:{
                char tenSVCanTim[50];
                printf("Nhap ten sinh vien: ");
                getchar();
                fgets(tenSVCanTim, sizeof(tenSVCanTim), stdin);
                tenSVCanTim[strcspn(tenSVCanTim, "\n")] = '\0';
                timKiemTheoTenSV(head, tenSVCanTim);
				break;
			}
			case 0:{
				break;
			}
		}
	}while(luaChon!=0);

	return 0;
}




